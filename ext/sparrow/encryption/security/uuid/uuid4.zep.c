
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid_Uuid4)
{
	ZEPHIR_REGISTER_CLASS_EX(Sparrow\\Encryption\\Security\\Uuid, Uuid4, sparrow, encryption_security_uuid_uuid4, sparrow_encryption_security_uuid_ce, sparrow_encryption_security_uuid_uuid4_method_entry, 0);

	zephir_declare_class_constant_long(sparrow_encryption_security_uuid_uuid4_ce, SL("TYPE"), 4);

	return SUCCESS;
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid4, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uuid_param = NULL, hash$$3, _0$$3, _1$$3, _2$$3;
	zval uuid;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uuid);
	ZVAL_UNDEF(&hash$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(uuid)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uuid_param);
	if (!uuid_param) {
		ZEPHIR_INIT_VAR(&uuid);
	} else {
		zephir_get_strval(&uuid, uuid_param);
	}


	if (ZEPHIR_IS_NULL(&uuid)) {
		ZVAL_LONG(&_1$$3, 16);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "bytes", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&hash$$3, "bin2hex", NULL, 71, &_0$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_1$$3, 4);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "format", NULL, 0, &hash$$3, &_1$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_2$$3);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &uuid);
	}
	ZEPHIR_MM_RESTORE();
}

