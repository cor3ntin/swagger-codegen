package com.wordnik.swagger.codegen;

import java.util.*;

public class CodegenResponse {
  public String code, message;
  public List<Map<String, String>> examples;
  Object schema;

  public String dataType, baseType, containerType;
  public Boolean simpleType = Boolean.FALSE;
  public Boolean primitiveType = Boolean.FALSE;
  public Boolean isMapContainer = Boolean.FALSE;
  public Boolean isListContainer = Boolean.FALSE;

  public Boolean hasMore;
}