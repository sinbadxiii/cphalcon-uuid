
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Encryption\Security\Random
 *
 * Secure random number generator class.
 *
 * Provides secure random number generator which is suitable for generating
 * session key in HTTP cookies, etc.
 *
 * `Phalcon\Encryption\Security\Random` could be mainly useful for:
 *
 * - Key generation (e.g. generation of complicated keys)
 * - Generating random passwords for new user accounts
 * - Encryption systems
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * // Random binary string
 * $bytes = $random->bytes();
 *
 * // Random hex string
 * echo $random->hex(10); // a29f470508d5ccb8e289
 * echo $random->hex(10); // 533c2f08d5eee750e64a
 * echo $random->hex(11); // f362ef96cb9ffef150c9cd
 * echo $random->hex(12); // 95469d667475125208be45c4
 * echo $random->hex(13); // 05475e8af4a34f8f743ab48761
 *
 * // Random base62 string
 * echo $random->base62(); // z0RkwHfh8ErDM1xw
 *
 * // Random base64 string
 * echo $random->base64(12); // XfIN81jGGuKkcE1E
 * echo $random->base64(12); // 3rcq39QzGK9fUqh8
 * echo $random->base64();   // DRcfbngL/iOo9hGGvy1TcQ==
 * echo $random->base64(16); // SvdhPcIHDZFad838Bb0Swg==
 *
 * // Random URL-safe base64 string
 * echo $random->base64Safe();           // PcV6jGbJ6vfVw7hfKIFDGA
 * echo $random->base64Safe();           // GD8JojhzSTrqX7Q8J6uug
 * echo $random->base64Safe(8);          // mGyy0evy3ok
 * echo $random->base64Safe(null, true); // DRrAgOFkS4rvRiVHFefcQ==
 *
 * // Random UUID
 * echo $random->uuid(); // db082997-2572-4e2c-a046-5eefe97b1235
 * echo $random->uuid(); // da2aa0e2-b4d0-4e3c-99f5-f5ef62c57fe2
 * echo $random->uuid(); // 75e6b628-c562-4117-bb76-61c4153455a9
 * echo $random->uuid(); // dc446df1-0848-4d05-b501-4af3c220c13d
 *
 * // Random number between 0 and $len
 * echo $random->number(256); // 84
 * echo $random->number(256); // 79
 * echo $random->number(100); // 29
 * echo $random->number(300); // 40
 *
 * // Random base58 string
 * echo $random->base58();   // 4kUgL2pdQMSCQtjE
 * echo $random->base58();   // Umjxqf7ZPwh765yR
 * echo $random->base58(24); // qoXcgmw4A9dys26HaNEdCRj9
 * echo $random->base58(7);  // 774SJD3vgP
 *```
 *
 * This class partially borrows SecureRandom library from Ruby
 *
 * @link https://ruby-doc.org/stdlib-2.2.2/libdoc/securerandom/rdoc/SecureRandom.html
 */
ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Random)
{
	ZEPHIR_REGISTER_CLASS_EX(Sparrow\\Encryption\\Security, Random, sparrow, encryption_security_random, sparrow_encryption_security_binarybase_ce, sparrow_encryption_security_random_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Sparrow_Encryption_Security_Random, uuid1)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uuid_param = NULL, *node_param = NULL;
	zval uuid, node;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uuid);
	ZVAL_UNDEF(&node);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(uuid)
		Z_PARAM_STR_OR_NULL(node)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &uuid_param, &node_param);
	if (!uuid_param) {
		ZEPHIR_INIT_VAR(&uuid);
	} else {
		zephir_get_strval(&uuid, uuid_param);
	}
	if (!node_param) {
		ZEPHIR_INIT_VAR(&node);
	} else {
		zephir_get_strval(&node, node_param);
	}


	object_init_ex(return_value, sparrow_encryption_security_uuid_uuid1_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 12, &uuid);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Random, uuid3)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *ns, ns_sub, *name_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ns_sub);
	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(ns)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns, &name_param);
	zephir_get_strval(&name, name_param);


	object_init_ex(return_value, sparrow_encryption_security_uuid_uuid3_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 13, ns, &name);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Random, uuid4)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	object_init_ex(return_value, sparrow_encryption_security_uuid_uuid4_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 14);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Random, uuid5)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *ns, ns_sub, *name_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ns_sub);
	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(ns)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns, &name_param);
	zephir_get_strval(&name, name_param);


	object_init_ex(return_value, sparrow_encryption_security_uuid_uuid5_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 15, ns, &name);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Random, uuid6)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	object_init_ex(return_value, sparrow_encryption_security_uuid_uuid6_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 16);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Sparrow_Encryption_Security_Random, uuid)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "uuid4", NULL, 0);
	zephir_check_call_status();
	zephir_cast_to_string(&_1, &_0);
	RETURN_CTOR(&_1);
}

