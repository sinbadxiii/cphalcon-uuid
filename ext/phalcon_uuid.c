
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "phalcon_uuid.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *sparrow_encryption_crypt_padding_padinterface_ce;
zend_class_entry *sparrow_encryption_security_uuid_nodeproviderinterface_ce;
zend_class_entry *sparrow_encryption_security_uuid_timebaseduidinterface_ce;
zend_class_entry *sparrow_encryption_crypt_cryptinterface_ce;
zend_class_entry *sparrow_encryption_security_binarybase_ce;
zend_class_entry *sparrow_encryption_security_uuid_ce;
zend_class_entry *sparrow_encryption_crypt_exception_exception_ce;
zend_class_entry *sparrow_0__closure_ce;
zend_class_entry *sparrow_encryption_crypt_ce;
zend_class_entry *sparrow_encryption_crypt_exception_mismatch_ce;
zend_class_entry *sparrow_encryption_crypt_padding_ansi_ce;
zend_class_entry *sparrow_encryption_crypt_padding_iso10126_ce;
zend_class_entry *sparrow_encryption_crypt_padding_isoiek_ce;
zend_class_entry *sparrow_encryption_crypt_padding_noop_ce;
zend_class_entry *sparrow_encryption_crypt_padding_pkcs7_ce;
zend_class_entry *sparrow_encryption_crypt_padding_space_ce;
zend_class_entry *sparrow_encryption_crypt_padding_zero_ce;
zend_class_entry *sparrow_encryption_security_ce;
zend_class_entry *sparrow_encryption_security_exception_ce;
zend_class_entry *sparrow_encryption_security_random_ce;
zend_class_entry *sparrow_encryption_security_uuid_randomnodeprovider_ce;
zend_class_entry *sparrow_encryption_security_uuid_sysnodeprovider_ce;
zend_class_entry *sparrow_encryption_security_uuid_uuid1_ce;
zend_class_entry *sparrow_encryption_security_uuid_uuid3_ce;
zend_class_entry *sparrow_encryption_security_uuid_uuid4_ce;
zend_class_entry *sparrow_encryption_security_uuid_uuid5_ce;
zend_class_entry *sparrow_encryption_security_uuid_uuid6_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalcon_uuid)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(phalcon_uuid)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_Padding_PadInterface);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Uuid_NodeProviderInterface);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Uuid_TimeBasedUidInterface);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_CryptInterface);
	ZEPHIR_INIT(Sparrow_Encryption_Security_BinaryBase);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Uuid);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_Exception_Exception);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_Exception_Mismatch);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_Padding_Ansi);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_Padding_Iso10126);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_Padding_IsoIek);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_Padding_Noop);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_Padding_Pkcs7);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_Padding_Space);
	ZEPHIR_INIT(Sparrow_Encryption_Crypt_Padding_Zero);
	ZEPHIR_INIT(Sparrow_Encryption_Security);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Exception);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Random);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Uuid_RandomNodeProvider);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Uuid_SysNodeProvider);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Uuid_Uuid1);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Uuid_Uuid3);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Uuid_Uuid4);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Uuid_Uuid5);
	ZEPHIR_INIT(Sparrow_Encryption_Security_Uuid_Uuid6);
	ZEPHIR_INIT(sparrow_0__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phalcon_uuid)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_phalcon_uuid_globals *phalcon_uuid_globals)
{
	phalcon_uuid_globals->initialized = 0;

	/* Cache Enabled */
	phalcon_uuid_globals->cache_enabled = 1;

	/* Recursive Lock */
	phalcon_uuid_globals->recursive_lock = 0;

	/* Static cache */
	memset(phalcon_uuid_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_phalcon_uuid_globals *phalcon_uuid_globals)
{
	
}

static PHP_RINIT_FUNCTION(phalcon_uuid)
{
	zend_phalcon_uuid_globals *phalcon_uuid_globals_ptr;
	phalcon_uuid_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(phalcon_uuid_globals_ptr);
	zephir_initialize_memory(phalcon_uuid_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phalcon_uuid)
{
	
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(phalcon_uuid)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PHALCON_UUID_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PHALCON_UUID_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PHALCON_UUID_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PHALCON_UUID_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PHALCON_UUID_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(phalcon_uuid)
{
#if defined(COMPILE_DL_PHALCON_UUID) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(phalcon_uuid_globals);
	php_zephir_init_module_globals(phalcon_uuid_globals);
}

static PHP_GSHUTDOWN_FUNCTION(phalcon_uuid)
{
	
}


zend_function_entry php_phalcon_uuid_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_phalcon_uuid_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry phalcon_uuid_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_phalcon_uuid_deps,
	PHP_PHALCON_UUID_EXTNAME,
	php_phalcon_uuid_functions,
	PHP_MINIT(phalcon_uuid),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(phalcon_uuid),
#else
	NULL,
#endif
	PHP_RINIT(phalcon_uuid),
	PHP_RSHUTDOWN(phalcon_uuid),
	PHP_MINFO(phalcon_uuid),
	PHP_PHALCON_UUID_VERSION,
	ZEND_MODULE_GLOBALS(phalcon_uuid),
	PHP_GINIT(phalcon_uuid),
	PHP_GSHUTDOWN(phalcon_uuid),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(phalcon_uuid),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_PHALCON_UUID
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(phalcon_uuid)
#endif
