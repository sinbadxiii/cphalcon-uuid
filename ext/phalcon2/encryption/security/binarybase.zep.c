
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Security_BinaryBase)
{
	ZEPHIR_REGISTER_CLASS(Phalcon2\\Encryption\\Security, BinaryBase, phalcon2, encryption_security_binarybase, phalcon2_encryption_security_binarybase_method_entry, 0);

	return SUCCESS;
}

/**
 * Generates a random base58 string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The result may contain alphanumeric characters except 0, O, I and l.
 *
 * It is similar to `Phalcon\Encryption\Security\Random::base64()` but has been
 * modified to avoid both non-alphanumeric characters and letters which
 * might look ambiguous when printed.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->base58(); // 4kUgL2pdQMSCQtjE
 *```
 *
 * @see    \Phalcon\Encryption\Security\Random:base64
 * @link   https://en.wikipedia.org/wiki/Base58
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, base58)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0, _1, _2;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(len, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len_param);
	if (!len_param) {
		len = 0;
	} else {
		len = zephir_get_intval(len_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz");
	ZVAL_LONG(&_1, 58);
	ZVAL_LONG(&_2, len);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "base", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random base62 string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 *
 * It is similar to `Phalcon\Encryption\Security\Random::base58()` but has been
 * modified to provide the largest value that can safely be used in URLs
 * without needing to take extra characters into consideration because it is
 * [A-Za-z0-9].
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->base62(); // z0RkwHfh8ErDM1xw
 *```
 *
 * @see    \Phalcon\Encryption\Security\Random:base58
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, base62)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0, _1, _2;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(len, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len_param);
	if (!len_param) {
		len = 0;
	} else {
		len = zephir_get_intval(len_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	ZVAL_LONG(&_1, 62);
	ZVAL_LONG(&_2, len);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "base", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random base64 string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The length of the result string is usually greater of $len.
 * Size formula: 4 * ($len / 3) rounded up to a multiple of 4.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->base64(12); // 3rcq39QzGK9fUqh8
 *```
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, base64)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0, _1;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(len, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len_param);
	if (!len_param) {
		len = 0;
	} else {
		len = zephir_get_intval(len_param);
	}


	ZVAL_LONG(&_1, len);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 1, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random URL-safe base64 string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The length of the result string is usually greater of $len.
 *
 * By default, padding is not generated because "=" may be used as a URL
 * delimiter. The result may contain A-Z, a-z, 0-9, "-" and "_". "=" is also
 * used if $padding is true. See RFC 3548 for the definition of URL-safe
 * base64.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->base64Safe(); // GD8JojhzSTrqX7Q8J6uug
 *```
 *
 * @link https://www.ietf.org/rfc/rfc3548.txt
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, base64Safe)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool padding;
	zval *len_param = NULL, *padding_param = NULL, s, _0, _1, _2, _3, _4, _5, _6$$3;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(len, is_null_true)
		Z_PARAM_BOOL(padding)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &len_param, &padding_param);
	if (!len_param) {
		len = 0;
	} else {
		len = zephir_get_intval(len_param);
	}
	if (!padding_param) {
		padding = 0;
	} else {
		padding = zephir_get_boolval(padding_param);
	}


	ZVAL_LONG(&_1, len);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "base64", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "base64_encode", NULL, 1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "+/");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "-_");
	ZEPHIR_CALL_FUNCTION(&s, "strtr", NULL, 2, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "#[^a-z0-9_=-]+#i");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "");
	ZEPHIR_CALL_FUNCTION(&_5, "preg_replace", NULL, 3, &_3, &_4, &s);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&s, &_5);
	if (!(padding)) {
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "=");
		zephir_fast_trim(return_value, &s, &_6$$3, ZEPHIR_TRIM_RIGHT);
		RETURN_MM();
	}
	RETURN_CCTOR(&s);
}

/**
 * Generates a random binary string
 *
 * The `Random::bytes` method returns a string and accepts as input an int
 * representing the length in bytes to be returned.
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The result may contain any byte: "x00" - "xFF".
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * $bytes = $random->bytes();
 * var_dump(bin2hex($bytes));
 * // Possible output: string(32) "00f6c04b144b41fad6a59111c126e1ee"
 *```
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, bytes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len_param);
	if (!len_param) {
		len = 16;
	} else {
		len = zephir_get_intval(len_param);
	}


	if (len <= 0) {
		len = 16;
	}
	ZVAL_LONG(&_0, len);
	ZEPHIR_RETURN_CALL_FUNCTION("random_bytes", NULL, 4, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random hex string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The length of the result string is usually greater of $len.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->hex(10); // a29f470508d5ccb8e289
 *```
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, hex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0, _1, _2, _3;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(len, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len_param);
	if (!len_param) {
		len = 0;
	} else {
		len = zephir_get_intval(len_param);
	}


	ZVAL_LONG(&_1, len);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "H*");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 5, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&_3);
	ZEPHIR_RETURN_CALL_FUNCTION("array_shift", NULL, 6, &_3);
	ZEPHIR_UNREF(&_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random number between 0 and $len
 *
 * Returns an integer: 0 <= result <= $len.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->number(16); // 8
 *```
 * @throws Exception If secure random number generator is not available,
 *                   unexpected partial read or $len <= 0
 */
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, number)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0, _1;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &len_param);
	len = zephir_get_intval(len_param);


	if (UNEXPECTED(len <= 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon2_encryption_security_exception_ce, "Input number must be a positive integer", "phalcon2/Encryption/Security/BinaryBase.zep", 207);
		return;
	}
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, len);
	ZEPHIR_RETURN_CALL_FUNCTION("random_int", NULL, 7, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random string based on the number ($base) of characters
 * ($alphabet).
 *
 * If $n is not specified, 16 is assumed. It may be larger in future.
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, base)
{
	unsigned char _7$$3, _10$$5;
	double _4$$3, _8$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long base, ZEPHIR_LAST_CALL_STATUS;
	zval *alphabet_param = NULL, *base_param = NULL, *n = NULL, n_sub, __$null, bytes, idx, _0, _1, *_2, _3, _5$$4, _9$$6;
	zval alphabet, byteString;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alphabet);
	ZVAL_UNDEF(&byteString);
	ZVAL_UNDEF(&n_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(alphabet)
		Z_PARAM_LONG(base)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(n)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &alphabet_param, &base_param, &n);
	zephir_get_strval(&alphabet, alphabet_param);
	base = zephir_get_intval(base_param);
	if (!n) {
		n = &n_sub;
		n = &__$null;
	}


	ZEPHIR_INIT_VAR(&byteString);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, n);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "C*");
	ZEPHIR_CALL_FUNCTION(&bytes, "unpack", NULL, 5, &_1, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&bytes, 0, "phalcon2/Encryption/Security/BinaryBase.zep", 241);
	if (Z_TYPE_P(&bytes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&bytes), _2)
		{
			ZEPHIR_INIT_NVAR(&idx);
			ZVAL_COPY(&idx, _2);
			_4$$3 = zephir_safe_mod_zval_long(&idx, 64);
			ZEPHIR_INIT_NVAR(&idx);
			ZVAL_DOUBLE(&idx, _4$$3);
			if (ZEPHIR_GE_LONG(&idx, base)) {
				ZVAL_LONG(&_5$$4, (base - 1));
				ZEPHIR_CALL_METHOD(&idx, this_ptr, "number", &_6, 0, &_5$$4);
				zephir_check_call_status();
			}
			_7$$3 = ZEPHIR_STRING_OFFSET(&alphabet, zephir_get_intval(&idx));
			zephir_concat_self_char(&byteString, _7$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &bytes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &bytes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&idx, &bytes, "current", NULL, 0);
			zephir_check_call_status();
				_8$$5 = zephir_safe_mod_zval_long(&idx, 64);
				ZEPHIR_INIT_NVAR(&idx);
				ZVAL_DOUBLE(&idx, _8$$5);
				if (ZEPHIR_GE_LONG(&idx, base)) {
					ZVAL_LONG(&_9$$6, (base - 1));
					ZEPHIR_CALL_METHOD(&idx, this_ptr, "number", &_6, 0, &_9$$6);
					zephir_check_call_status();
				}
				_10$$5 = ZEPHIR_STRING_OFFSET(&alphabet, zephir_get_intval(&idx));
				zephir_concat_self_char(&byteString, _10$$5);
			ZEPHIR_CALL_METHOD(NULL, &bytes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&idx);
	RETURN_CTOR(&byteString);
}

