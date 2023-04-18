
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon2_0__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon2, 0__closure, phalcon2, 0__closure, phalcon2_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(phalcon2_0__closure, __invoke)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *address_param = NULL, _1, _2, _3, _4;
	zval address;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(address)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &address_param);
	zephir_get_strval(&address, address_param);


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&address, "00:00:00:00:00:00");
	if (_0) {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "/^([0-9a-f]{2}:){5}[0-9a-f]{2}$/i");
		ZEPHIR_INIT_VAR(&_3);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "/^([0-9a-f]{2}:){5}[0-9a-f]{2}$/i");
		zephir_preg_match(&_3, &_4, &address, &_1, 0, 0 , 0 );
		_0 = zephir_is_true(&_3);
	}
	RETURN_MM_BOOL(_0);
}

