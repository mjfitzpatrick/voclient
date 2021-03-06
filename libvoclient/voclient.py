# This file was automatically generated by SWIG (http://www.swig.org).
# Version 1.3.31
#
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _voclient
import new
new_instancemethod = new.instancemethod
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'PySwigObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types


voc_coneCaller = _voclient.voc_coneCaller
voc_coneCallerToFile = _voclient.voc_coneCallerToFile
voc_siapCaller = _voclient.voc_siapCaller
voc_siapCallerToFile = _voclient.voc_siapCallerToFile
voc_ssapCaller = _voclient.voc_ssapCaller
voc_ssapCallerToFile = _voclient.voc_ssapCallerToFile
voc_getRawURL = _voclient.voc_getRawURL
voc_validateObject = _voclient.voc_validateObject
voc_initVOClient = _voclient.voc_initVOClient
voc_closeVOClient = _voclient.voc_closeVOClient
voc_abortVOClient = _voclient.voc_abortVOClient
voc_openConnection = _voclient.voc_openConnection
voc_openConeConnection = _voclient.voc_openConeConnection
voc_openSiapConnection = _voclient.voc_openSiapConnection
voc_openSsapConnection = _voclient.voc_openSsapConnection
voc_closeConnection = _voclient.voc_closeConnection
voc_getServiceCount = _voclient.voc_getServiceCount
voc_addServiceURL = _voclient.voc_addServiceURL
voc_getServiceURL = _voclient.voc_getServiceURL
voc_getQuery = _voclient.voc_getQuery
voc_getConeQuery = _voclient.voc_getConeQuery
voc_getSiapQuery = _voclient.voc_getSiapQuery
voc_getSsapQuery = _voclient.voc_getSsapQuery
voc_addIntParam = _voclient.voc_addIntParam
voc_addFloatParam = _voclient.voc_addFloatParam
voc_addStringParam = _voclient.voc_addStringParam
voc_getQueryString = _voclient.voc_getQueryString
voc_executeQuery = _voclient.voc_executeQuery
voc_executeCSV = _voclient.voc_executeCSV
voc_executeVOTable = _voclient.voc_executeVOTable
voc_executeQueryAs = _voclient.voc_executeQueryAs
voc_getRecordCount = _voclient.voc_getRecordCount
voc_getRecord = _voclient.voc_getRecord
voc_getFieldAttr = _voclient.voc_getFieldAttr
voc_getAttribute = _voclient.voc_getAttribute
voc_intValue = _voclient.voc_intValue
voc_floatValue = _voclient.voc_floatValue
voc_stringValue = _voclient.voc_stringValue
voc_getIntAttr = _voclient.voc_getIntAttr
voc_getFloatAttr = _voclient.voc_getFloatAttr
voc_getStringAttr = _voclient.voc_getStringAttr
voc_getAttrList = _voclient.voc_getAttrList
voc_getAttrCount = _voclient.voc_getAttrCount
voc_getDataset = _voclient.voc_getDataset
voc_debugLevel = _voclient.voc_debugLevel
voc_regSearch = _voclient.voc_regSearch
voc_regSearchByService = _voclient.voc_regSearchByService
voc_regQuery = _voclient.voc_regQuery
voc_regAddSearchTerm = _voclient.voc_regAddSearchTerm
voc_regRemoveSearchTerm = _voclient.voc_regRemoveSearchTerm
voc_regGetSTCount = _voclient.voc_regGetSTCount
voc_regGetQueryString = _voclient.voc_regGetQueryString
voc_regExecute = _voclient.voc_regExecute
voc_regExecuteRaw = _voclient.voc_regExecuteRaw
voc_resGetCount = _voclient.voc_resGetCount
voc_resGetStr = _voclient.voc_resGetStr
voc_resGetFloat = _voclient.voc_resGetFloat
voc_resGetInt = _voclient.voc_resGetInt
voc_nameResolver = _voclient.voc_nameResolver
voc_resolverPos = _voclient.voc_resolverPos
voc_resolverRA = _voclient.voc_resolverRA
voc_resolverDEC = _voclient.voc_resolverDEC
voc_resolverRAErr = _voclient.voc_resolverRAErr
voc_resolverDECErr = _voclient.voc_resolverDECErr
voc_resolverOtype = _voclient.voc_resolverOtype
voc_skybot = _voclient.voc_skybot
voc_skybotNObjs = _voclient.voc_skybotNObjs
voc_skybotStrAttr = _voclient.voc_skybotStrAttr
voc_skybotDblAttr = _voclient.voc_skybotDblAttr


