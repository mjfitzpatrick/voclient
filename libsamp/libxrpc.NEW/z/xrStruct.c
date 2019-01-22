/**
 *
 *  XRSTRUCT.C
 *
 *  Methods used to implement the Struct object.
 *
 *
 *         snum = xr_newStruct ()
 *               xr_freeStruct (int snum)
 *
 *           xr_setIntInStruct (int snum, char *key, int value)
 *        xr_setDoubleInStruct (int snum, char *key, double value)
 *          xr_setBoolInStruct (int snum, char *key, int value)
 *        xr_setStringInStruct (int snum, char *key, char *value)
 *      xr_setDatetimeInStruct (int snum, char *key, char *value)
 *        xr_setStructInStruct (int snum, char *key, int value)
 *         xr_setArrayInStruct (int snum, char *key, int value)
 *
 *         xr_getIntFromStruct (int snum, char *key, int *value)
 *      xr_getDoubleFromStruct (int snum, char *key, double *value)
 *        xr_getBoolFromStruct (int snum, char *key, int *value)
 *      xr_getStringFromStruct (int snum, char *key, char **value)
 *    xr_getDatetimeFromStruct (int snum, char *key, char **value)
 *      xr_getStructFromStruct (int snum, char *key, int *value)
 *       xr_getArrayFromStruct (int snum, char *key, int *value)
 *
 *
 *  @brief      Methods used to manage Struct objects.
 *
 *  @file       xrStruct.c
 *  @author     Mike Fitzpatrick
 *  @date       6/10/09
 */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <xmlrpc-c/base.h>
#include <xmlrpc-c/client.h>
#include <xmlrpc-c/server.h>
#include <xmlrpc-c/server_abyss.h>

#include "xrpcP.h"


#define SZ_NAME		64


typedef struct {
    xmlrpc_value  *val;				/* struct value		*/

    int	   in_use;

} PStruct, *PStructP;


int	nstructs	= -1;
PStruct	sParams[MAX_STRUCTS];

xmlrpc_env env;					/* local env		*/



/**
 *  XR_NEWSTRUCT -- Create a new Struct type value.
 */
int
xr_newStruct ()
{
    int  i;
    PStruct *p;;


    if (nstructs < 0) 		/* initialize the Struct array */
	memset (&sParams[0], 0, MAX_STRUCTS * sizeof(PStruct) );

    nstructs++;
    for (i=0; i < MAX_STRUCTS; i++) {
	p = &sParams[i];
	if (! p->in_use) {
    	    p->in_use = TRUE;
	    if (p->val)
    	        xmlrpc_DECREF (p->val);
    	    memset (p, 0, sizeof(PStruct) );

	    p->val = xmlrpc_struct_new (&env);

	 return (i);	
	}
    }

    return (-1);
}

void
xr_freeStruct (int snum)
{
    PStruct *p = &sParams[snum];

	    
/*    
    memset (&sParams[snum], 0, sizeof(PStruct) );
    xmlrpc_DECREF (p->val);

  */
  
    p->in_use = 0;
    nstructs--;
}


/* ******************************************************************** */


void
xr_setIntInStruct (int snum, char *key, int value)
{
    PStruct *p = &sParams[snum];

     xmlrpc_value *v = xmlrpc_int_new (&env, value);
    xmlrpc_struct_set_value (&env, (p->val), key, v);
    xmlrpc_DECREF(v);
    
}

void
xr_setDoubleInStruct (int snum, char *key, double value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *v = xmlrpc_double_new (&env, value);

    xmlrpc_struct_set_value (&env, p->val, key, v);
    xmlrpc_DECREF(v);
}


void
xr_setLongLongInStruct ( int snum, char *key, long long value)
{
	PStruct *p = &sParams[snum];
	xmlrpc_value *v = xmlrpc_i8_new (&env,value);
	
	xmlrpc_struct_set_value(&env,p->val,key,v);
	xmlrpc_DECREF(v);
}

void
xr_setBoolInStruct (int snum, char *key, int value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *v = xmlrpc_bool_new (&env, (xmlrpc_bool) value);

    xmlrpc_struct_set_value (&env, p->val, key, v);
    xmlrpc_DECREF(v);
}

void
xr_setStringInStruct (int snum, char *key, char *value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *v = xmlrpc_string_new (&env, value);

    xmlrpc_struct_set_value (&env, p->val, key, v);
    xmlrpc_DECREF(v);
}

void
xr_setDatetimeInStruct (int snum, char *key, char *value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *v = xmlrpc_string_new (&env, (const char *)value);

    xmlrpc_struct_set_value (&env, p->val, key, v);
    xmlrpc_DECREF(v);
}

void
xr_setStructInStruct (int snum, char *key, int value)
{
    PStruct *p = &sParams[snum];
    PStruct *n = &sParams[value];

    xmlrpc_struct_set_value (&env, p->val, key, n->val);
}

void
xr_setArrayInStruct (int snum, char *key, int value)
{
    PStruct *p = &sParams[snum];

    xmlrpc_struct_set_value (&env, p->val, key, xr_getAElement (value) );
}



/**************************************************************************
**  Procedures used to extract values from a struct.
*/


void
xr_getLongLongFromStruct(int snum, char*key, long long value)
{
	PStruct *p = &sParams[snum];
	xmlrpc_value *s = p->val;
	xmlrpc_value *v = (xmlrpc_value *) NULL;

    if (xmlrpc_struct_has_key (&env, s, (const char *) key)) {
        xmlrpc_struct_find_value (&env, s, (const char *)key, &v);
	xmlrpc_read_i8 (&env, v, value);
	

	}



}
void
xr_getIntFromStruct (int snum, char *key, int *value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *s = p->val;
    xmlrpc_value *v = (xmlrpc_value *) NULL;

    if (xmlrpc_struct_has_key (&env, s, (const char *) key)) {
        xmlrpc_struct_find_value (&env, s, (const char *)key, &v);
	xmlrpc_read_int (&env, v, value);
	
    }

}

void
xr_getDoubleFromStruct (int snum, char *key, double *value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *s = p->val;
    xmlrpc_value *v = (xmlrpc_value *) NULL;

    if (xmlrpc_struct_has_key (&env, s, (const char *) key)) {
        xmlrpc_struct_find_value (&env, s, (const char *)key, &v);
	xmlrpc_read_double (&env, v, value);
    }
}

void
xr_getBoolFromStruct (int snum, char *key, int *value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *s = p->val;
    xmlrpc_value *v = (xmlrpc_value *) NULL;

    if (xmlrpc_struct_has_key (&env, s, (const char *) key)) {
        xmlrpc_struct_find_value (&env, s, (const char *)key, &v);
	xmlrpc_read_bool (&env, v, (xmlrpc_bool *)value);
    }

}

void
xr_getStringFromStruct (int snum, char *key, char **value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *s = p->val;
    xmlrpc_value *v = (xmlrpc_value *) NULL;
    const char *str = (char *) NULL;


    if (xmlrpc_struct_has_key (&env, s, (const char *) key)) {
        xmlrpc_struct_find_value (&env, s, (const char *)key, &v);
	xmlrpc_read_string (&env, v, &str);
	strcpy (*value, str);
        free ((void *) str);
    }

}

void
xr_getDatetimeFromStruct (int snum, char *key, char **value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *s = p->val;
    xmlrpc_value *v = (xmlrpc_value *) NULL;
    const char *str = (char *) NULL;


    if (xmlrpc_struct_has_key (&env, s, (const char *) key)) {
        xmlrpc_struct_find_value (&env, s, (const char *)key, &v);
	xmlrpc_read_datetime_str (&env, v, &str);
	strcpy (*value, str);
        free ((void *) str);
    }
}

void
xr_getStructFromStruct (int snum, char *key, int *value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *s = p->val;
    xmlrpc_value *v = (xmlrpc_value *) NULL;


    if (xmlrpc_struct_has_key (&env, s, (const char *) key)) {
        xmlrpc_struct_find_value (&env, s, (const char *)key, &v);

	*value = xr_newStruct ();
	xr_setSParam (*value, v);
    }
}

void
xr_getArrayFromStruct (int snum, char *key, int *value)
{
    PStruct *p = &sParams[snum];
    xmlrpc_value *s = p->val;
    xmlrpc_value *v = (xmlrpc_value *) NULL;


    if (xmlrpc_struct_has_key (&env, s, (const char *) key)) {
        xmlrpc_struct_find_value (&env, s, (const char *)key, &v);

	*value = xr_newArray ();
	xr_setAElement (*value, v);
    }
}



/* Set/Get params.
*/

xmlrpc_value *
xr_getSParam (int snum)
{
    PStruct *p = &sParams[snum];
    return (p->val);
}

void
xr_setSParam (int snum, xmlrpc_value *v)
{
    PStruct *p = &sParams[snum];
    p->val = v;
}

