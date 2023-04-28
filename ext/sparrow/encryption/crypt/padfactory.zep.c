
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class PadFactory
 *
 * @package Phalcon\Crypt
 */
ZEPHIR_INIT_CLASS(Sparrow_Encryption_Crypt_PadFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Sparrow\\Encryption\\Crypt, PadFactory, sparrow, encryption_crypt_padfactory, zephir_get_internal_ce(SL("phalcon\\factory\\abstractfactory")), sparrow_encryption_crypt_padfactory_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(sparrow_encryption_crypt_padfactory_ce, SL("exception"), "Sparrow\\Encryption\\Crypt\\Exception\\Exception", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * AdapterFactory constructor.
 */
PHP_METHOD(Sparrow_Encryption_Crypt_PadFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(services)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Create a new instance of the adapter
 */
PHP_METHOD(Sparrow_Encryption_Crypt_PadFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, definition;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}


	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, &definition);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets a Crypt pad constant and returns the unique service name for the
 * padding class
 *
 * @param int $number
 *
 * @return string
 */
PHP_METHOD(Sparrow_Encryption_Crypt_PadFactory, padNumberToService)
{
	zend_class_entry *_1 = NULL;
	zval map;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *number_param = NULL, _0, _2, _3;
	zend_long number, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&map);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(number)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number_param);
	number = zephir_get_intval(number_param);


	ZEPHIR_INIT_VAR(&map);
	zephir_create_array(&map, 6, 0);
	add_index_stringl(&map, 1, SL("ansi"));
	add_index_stringl(&map, 3, SL("iso10126"));
	add_index_stringl(&map, 4, SL("isoiek"));
	add_index_stringl(&map, 2, SL("pjcs7"));
	add_index_stringl(&map, 6, SL("space"));
	add_index_stringl(&map, 5, SL("zero"));
	ZEPHIR_INIT_VAR(&_0);
	if (!_1) {
	_1 = zephir_fetch_class_str_ex(SL("Phalcon\\Support\\Helper\\Arr\\Get"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_0, _1);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_LONG(&_2, number);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "noop");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "__invoke", NULL, 0, &map, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string[]
 */
PHP_METHOD(Sparrow_Encryption_Crypt_PadFactory, getServices)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 7, 0);
	add_assoc_stringl_ex(return_value, SL("ansi"), SL("Sparrow\\Encryption\\Crypt\\Padding\\Ansi"));
	add_assoc_stringl_ex(return_value, SL("iso10126"), SL("Sparrow\\Encryption\\Crypt\\Padding\\Iso10126"));
	add_assoc_stringl_ex(return_value, SL("isoiek"), SL("Sparrow\\Encryption\\Crypt\\Padding\\IsoIek"));
	add_assoc_stringl_ex(return_value, SL("noop"), SL("Sparrow\\Encryption\\Crypt\\Padding\\Noop"));
	add_assoc_stringl_ex(return_value, SL("pjcs7"), SL("Sparrow\\Encryption\\Crypt\\Padding\\Pkcs7"));
	add_assoc_stringl_ex(return_value, SL("space"), SL("Sparrow\\Encryption\\Crypt\\Padding\\Space"));
	add_assoc_stringl_ex(return_value, SL("zero"), SL("Sparrow\\Encryption\\Crypt\\Padding\\Zero"));
	return;
}

