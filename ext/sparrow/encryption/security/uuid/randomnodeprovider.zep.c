
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid_RandomNodeProvider)
{
	ZEPHIR_REGISTER_CLASS(Sparrow\\Encryption\\Security\\Uuid, RandomNodeProvider, sparrow, encryption_security_uuid_randomnodeprovider, sparrow_encryption_security_uuid_randomnodeprovider_method_entry, 0);

	zend_class_implements(sparrow_encryption_security_uuid_randomnodeprovider_ce, 1, sparrow_encryption_security_uuid_nodeproviderinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_RandomNodeProvider, getNode)
{
	zval node, seed, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&seed);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&seed, this_ptr, "getseed", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, &seed, 0, PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid/RandomNodeProvider.zep", 12);
	zephir_array_fetch_long(&_1, &seed, 1, PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid/RandomNodeProvider.zep", 13);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "%06x%06x");
	ZVAL_LONG(&_3, ((int) (zephir_get_numberval(&_0)) | 0x010000));
	ZEPHIR_CALL_FUNCTION(&node, "sprintf", NULL, 9, &_2, &_3, &_1);
	zephir_check_call_status();
	RETURN_CCTOR(&node);
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_RandomNodeProvider, getSeed)
{
	zval _0, _1, _2;
	zval seed;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&seed);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&seed);
	zephir_create_array(&seed, 2, 0);
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 0xFFFFFF);
	ZEPHIR_CALL_FUNCTION(&_2, "random_int", NULL, 7, &_0, &_1);
	zephir_check_call_status();
	zephir_array_fast_append(&seed, &_2);
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 0xFFFFFF);
	ZEPHIR_CALL_FUNCTION(&_2, "random_int", NULL, 7, &_0, &_1);
	zephir_check_call_status();
	zephir_array_fast_append(&seed, &_2);
	RETURN_CTOR(&seed);
}

