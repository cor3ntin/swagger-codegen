package com.ankama.swagger.codegen.languages;

import com.wordnik.swagger.models.Operation;
import com.wordnik.swagger.models.parameters.Parameter;
import com.wordnik.swagger.util.Json;
import com.wordnik.swagger.codegen.*;
import com.wordnik.swagger.models.properties.*;
import sun.org.mozilla.javascript.optimizer.*;

import java.util.*;
import java.io.File;

public class QtClientCodegen extends DefaultCodegen implements CodegenConfig {
  protected Set<String> QtClasses;
  protected String sourceFolder = "client";

  public CodegenType getTag() {
    return CodegenType.CLIENT;
  }

  public String getName() {
    return "qt";
  }

  public String getHelp() {
    return "Qt5 / C++11 code generator - requires boost";
  }

  public QtClientCodegen() {
    super();
    outputFolder = "generated-code/qt/";
    modelTemplateFiles.put("model-header.mustache", ".h");
    modelTemplateFiles.put("model-body.mustache", ".cpp");
    apiTemplateFiles.put("api-header.mustache", ".h");
    apiTemplateFiles.put("api-body.mustache", ".cpp");
    templateDir = "qt";
    modelPackage = "";

    defaultIncludes = new HashSet<String>();
    languageSpecificPrimitives = new HashSet<String>(
            Arrays.asList(
                "bool",
                "int",
                "long", "double", "float",
                "qint8", "qint16", "qint32", "qint64",
                "quint8", "quint16", "quint32", "quint64"
            )
    );

    reservedWords = new HashSet<String>(
      Arrays.asList(
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char16_t",
        "char32_t", "class", "compl", "concept", "const", "constexpr", "const_cast", "continue",
        "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit",
        "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new",
        "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public",
        "register", "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static", "static_assert",
        "static_cast", "struct", "switch", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid",
        "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
      ));

    super.typeMapping = new HashMap<String, String>();

    typeMapping.put("Date", "QDate");
    typeMapping.put("DateTime", "QDateTime");
    typeMapping.put("string", "QString");
    typeMapping.put("integer", "qint32");
    typeMapping.put("float", "float");
    typeMapping.put("long", "qint64");
    typeMapping.put("boolean", "bool");
    typeMapping.put("double", "double");
    typeMapping.put("array", "QVector");
    typeMapping.put("map", "QHash");

    QtClasses = new HashSet<String> (
        Arrays.asList(
            "QString", "QVector", "QStringList", "QMap", "QHash", "QTime", "QDate", "QDateTime")
    );
    importMapping = new HashMap<String, String>();

    supportingFiles.clear();
    supportingFiles.add(new SupportingFile("response-header.mustache", sourceFolder, "AbstractResponse.h"));
    supportingFiles.add(new SupportingFile("response-body.mustache", sourceFolder, "AbstractResponse.cpp"));
    supportingFiles.add(new SupportingFile("invoker-header.mustache", sourceFolder, "ApiInvoker.h"));
    supportingFiles.add(new SupportingFile("invoker-body.mustache", sourceFolder, "ApiInvoker.cpp"));
    supportingFiles.add(new SupportingFile("utils-header.mustache", sourceFolder, "SwaggerUtils.h"));
    supportingFiles.add(new SupportingFile("utils-body.mustache", sourceFolder, "SwaggerUtils.cpp"));
  }

  @Override
  public String toInstantiationType(Property p) {
    if (p instanceof MapProperty) {
      MapProperty ap = (MapProperty) p;
      String inner = getSwaggerType(ap.getAdditionalProperties());
      return instantiationTypes.get("map");
    }
    else if (p instanceof ArrayProperty) {
      ArrayProperty ap = (ArrayProperty) p;
      String inner = getSwaggerType(ap.getItems());
      return instantiationTypes.get("array");
    }
    else
      return null;
  }

  @Override
  public String getSwaggerType(Property p) {
    String swaggerType = super.getSwaggerType(p);
    String type = null;
    if(typeMapping.containsKey(swaggerType)) {
      type = typeMapping.get(swaggerType);
      if(languageSpecificPrimitives.contains(type))
        return toModelName(type);
    }
    else
      type = swaggerType;
    return toModelName(type);
  }

  @Override
  public String getTypeDeclaration(Property p) {
    if(p instanceof ArrayProperty) {
      ArrayProperty ap = (ArrayProperty) p;
      Property inner = ap.getItems();
      String innerType = getTypeDeclaration(inner);

      if(innerType.compareTo("QString") == 0)
          return "QStringList";

      return getSwaggerType(p) + "<" + innerType + ">";
    }
    else if (p instanceof MapProperty) {
      MapProperty mp = (MapProperty) p;
      Property inner = mp.getAdditionalProperties();

      return getSwaggerType(p) + "<QString, " + getTypeDeclaration(inner) + ">";
    }
    return super.getTypeDeclaration(p);
  }

  @Override
  public String toModelName(String type) {
    if(typeMapping.keySet().contains(type) ||
      typeMapping.values().contains(type) ||
      importMapping.values().contains(type) ||
      defaultIncludes.contains(type) ||
      languageSpecificPrimitives.contains(type)) {
      return type;
    }
    else {
      return Character.toUpperCase(type.charAt(0)) + type.substring(1);
    }
  }

  @Override
  public String toModelImport(String name) {
      if(QtClasses.contains(name))
          return "#include <" + name + ">";
      return "#include \"" + name + ".h\"";
  }

  @Override
  public String toDefaultValue(Property p) {
    if(p instanceof StringProperty)
      return "QString::null";
    else if (p instanceof BooleanProperty)
      return "false";
    else if(p instanceof DateProperty)
      return "{}";
    else if(p instanceof DateTimeProperty)
      return "{}";
    else if (p instanceof DoubleProperty)
      return ".0";
    else if (p instanceof FloatProperty)
      return "0f";
    else if (p instanceof IntegerProperty)
      return "0";
    else if (p instanceof LongProperty)
      return "0";
    else if (p instanceof DecimalProperty)
      return "0";

    return getTypeDeclaration(p) + "()";
  }

  @Override
  public String apiFileFolder() {
    return outputFolder + File.separator + sourceFolder;
  }

  @Override
  public String modelFileFolder() {
    return outputFolder + File.separator + sourceFolder;
  }

  @Override
  public String toModelFilename(String name) {
    return initialCaps(name);
  }

  @Override
  public String toApiName(String name) {
    return initialCaps(name) + "Api";
  }

  public String toApiFilename(String name) {
    return initialCaps(name) + "Api";
  }

  @Override
  public String toVarName(String name) {
    String paramName = name.replaceAll("[^a-zA-Z0-9_]","");
    paramName = Character.toLowerCase(paramName.charAt(0)) + paramName.substring(1);
    return paramName;
  }

  @Override
  public String toParamName(String name) {
      String paramName = name.replaceAll("[^a-zA-Z0-9_]","");
      paramName = Character.toLowerCase(paramName.charAt(0)) + paramName.substring(1);
      return paramName;
  }


  public String escapeReservedWord(String name) {
    return "_" + name;
  }
}
