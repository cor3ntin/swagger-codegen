package com.ankama.swagger.codegen.languages;

import com.wordnik.swagger.models.Model;
import com.wordnik.swagger.models.Operation;
import com.wordnik.swagger.models.parameters.Parameter;
import com.wordnik.swagger.util.Json;
import com.wordnik.swagger.codegen.*;
import com.wordnik.swagger.models.properties.*;
import org.apache.commons.lang.StringUtils;
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
    apiTemplateFiles.put("api-header-public.mustache", ".h");
    apiTemplateFiles.put("api-body.mustache", ".cpp");
    apiTemplateFiles.put("api-header.mustache", "_p.h");
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
    typeMapping.put("number", "double");
    typeMapping.put("array", "QVector");
    typeMapping.put("map", "QHash");
    typeMapping.put("file", "QIODevice*");

    QtClasses = new HashSet<String>(
        Arrays.asList(
            "QString", "QVector", "QStringList", "QMap", "QHash", "QTime", "QDate", "QDateTime", "QIODevice")
    );
    importMapping.clear();

    supportingFiles.clear();
    supportingFiles.add(new SupportingFile("request-header.mustache", sourceFolder, "AbstractRequest.h"));
    supportingFiles.add(new SupportingFile("request-body.mustache", sourceFolder, "AbstractRequest.cpp"));
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
    } else if (p instanceof ArrayProperty) {
      ArrayProperty ap = (ArrayProperty) p;
      String inner = getSwaggerType(ap.getItems());
      return instantiationTypes.get("array");
    } else
      return null;
  }

  @Override
  public String getSwaggerType(Property p) {
    String swaggerType = super.getSwaggerType(p);
    String type = null;
    if (typeMapping.containsKey(swaggerType)) {
      type = typeMapping.get(swaggerType);
      if (languageSpecificPrimitives.contains(type))
        return toModelName(type);
    } else
      type = swaggerType;
    return toModelName(type);
  }

  @Override
  public String getTypeDeclaration(Property p) {
    if (p instanceof ArrayProperty) {
      ArrayProperty ap = (ArrayProperty) p;
      Property inner = ap.getItems();
      String innerType = getTypeDeclaration(inner);

      if (innerType.compareTo("QString") == 0)
        return "QStringList";

      return getSwaggerType(p) + "<" + innerType + ">";
    } else if (p instanceof MapProperty) {
      MapProperty mp = (MapProperty) p;
      Property inner = mp.getAdditionalProperties();

      return getSwaggerType(p) + "<QString, " + getTypeDeclaration(inner) + ">";
    }
    return super.getTypeDeclaration(p);
  }

  @Override
  public String toModelName(String type) {
    if (typeMapping.keySet().contains(type) ||
        typeMapping.values().contains(type) ||
        importMapping.values().contains(type) ||
        defaultIncludes.contains(type) ||
        languageSpecificPrimitives.contains(type)) {
      return type;
    } else {
      return Character.toUpperCase(type.charAt(0)) + type.substring(1);
    }
  }

  @Override
  public String toModelImport(String name) {
    String iname = name;
    if (iname.endsWith("*"))
      iname = iname.substring(0, iname.length() - 1);
    if (QtClasses.contains(iname))
      return "#include <" + iname + ">";
    return "#include \"" + iname + ".h\"";
  }

  @Override
  public String toDefaultValue(Property p) {
    return "{}";
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
    String paramName = name.replaceAll("[^a-zA-Z0-9_]", "");
    paramName = Character.toLowerCase(paramName.charAt(0)) + paramName.substring(1);
    return paramName;
  }

  @Override
  public String toParamName(String name) {
    String paramName = name.replaceAll("[^a-zA-Z0-9_]", "");
    paramName = Character.toLowerCase(paramName.charAt(0)) + paramName.substring(1);
    return paramName;
  }

  @Override
  public CodegenModel fromModel(String name, Model model) {
    //put required parameters first
    CodegenModel m = super.fromModel(name, model);
    List<CodegenProperty> params = new ArrayList<CodegenProperty>();
    ListIterator<CodegenProperty> it = m.vars.listIterator();
    while (it.hasNext()) {
      CodegenProperty p = it.next();
      if (p.required) {
        params.add(p);
        it.remove();
      }
    }
    params.addAll(m.vars);
    m.vars = params;

    it = m.vars.listIterator();
    while (it.hasNext()) {
      CodegenProperty p = it.next();
      p.hasMore = it.hasNext();
      p.secondaryParam = it.hasPrevious();
    }

    return m;
  }

  @Override
  public CodegenProperty fromProperty(String name, Property p) {
    CodegenProperty cp = super.fromProperty(name, p);
    if(cp.isEnum)
      cp.datatypeWithEnum = StringUtils.capitalize(cp.name);
    if(cp.getter != null)
      cp.getter = name;
    return cp;
  }

  private  List<CodegenParameter> sortCPPFunctionParameters(List<CodegenParameter> parameters) {
    List<CodegenParameter> required  = new ArrayList<CodegenParameter>();
    List<CodegenParameter> optionals = new ArrayList<CodegenParameter>();
    ListIterator<CodegenParameter> it = parameters.listIterator();
    while(it.hasNext()) {
      CodegenParameter p = it.next();
      if(p.required)
        required.add(p);
      else
        optionals.add(p);
    }
    required.addAll(optionals);

    it = required.listIterator();
    while(it.hasNext()) {
      CodegenParameter p = it.next();
      p.hasMore = it.hasNext();
      p.secondaryParam = it.hasPrevious();
    }
    return required;
  }

  @Override
  public CodegenOperation fromOperation(String path, String httpMethod, Operation operation) {
    //put required parameters first
    CodegenOperation op = super.fromOperation(path, httpMethod, operation);
    op.allParams = sortCPPFunctionParameters(op.allParams);
    op.formParams = sortCPPFunctionParameters(op.formParams);
    op.queryParams = sortCPPFunctionParameters(op.queryParams);
    op.headerParams = sortCPPFunctionParameters(op.headerParams);
    op.bodyParams = sortCPPFunctionParameters(op.bodyParams);
    op.pathParams = sortCPPFunctionParameters(op.pathParams);
    return op;
  }


  public String escapeReservedWord(String name) {
    return "_" + name;
  }
}
