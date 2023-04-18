
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PHALCON_UUID_H
#define PHP_PHALCON_UUID_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PHALCON_UUID_NAME        "Phalcon Uuid"
#define PHP_PHALCON_UUID_VERSION     "1.0.0"
#define PHP_PHALCON_UUID_EXTNAME     "phalcon_uuid"
#define PHP_PHALCON_UUID_AUTHOR      "Sergey Mukhin"
#define PHP_PHALCON_UUID_ZEPVERSION  "0.17.0-9f99da6"
#define PHP_PHALCON_UUID_DESCRIPTION "Phalcon Uuid"



ZEND_BEGIN_MODULE_GLOBALS(phalcon_uuid)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(phalcon_uuid)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phalcon_uuid)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(phalcon_uuid, v)
#else
	#define ZEPHIR_GLOBAL(v) (phalcon_uuid_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_phalcon_uuid_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(phalcon_uuid_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(phalcon_uuid_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def phalcon_uuid_globals
#define zend_zephir_globals_def zend_phalcon_uuid_globals

extern zend_module_entry phalcon_uuid_module_entry;
#define phpext_phalcon_uuid_ptr &phalcon_uuid_module_entry

#endif
