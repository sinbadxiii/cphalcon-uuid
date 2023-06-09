
extern zend_class_entry *phalcon_encryption_security_random_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Random);

PHP_METHOD(Phalcon_Encryption_Security_Random, base58);
PHP_METHOD(Phalcon_Encryption_Security_Random, base62);
PHP_METHOD(Phalcon_Encryption_Security_Random, base64);
PHP_METHOD(Phalcon_Encryption_Security_Random, base64Safe);
PHP_METHOD(Phalcon_Encryption_Security_Random, bytes);
PHP_METHOD(Phalcon_Encryption_Security_Random, hex);
PHP_METHOD(Phalcon_Encryption_Security_Random, number);
PHP_METHOD(Phalcon_Encryption_Security_Random, uuid1);
PHP_METHOD(Phalcon_Encryption_Security_Random, uuid);
PHP_METHOD(Phalcon_Encryption_Security_Random, base);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_random_base58, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_random_base62, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_random_base64, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_random_base64safe, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, padding, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_random_bytes, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_random_hex, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_random_number, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_random_uuid1, 0, 0, Phalcon\\Encryption\\Security\\Uuid\\Uuid1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_random_uuid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_random_base, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, alphabet, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, base, IS_LONG, 0)
	ZEND_ARG_INFO(0, n)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_security_random_method_entry) {
	PHP_ME(Phalcon_Encryption_Security_Random, base58, arginfo_phalcon_encryption_security_random_base58, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Random, base62, arginfo_phalcon_encryption_security_random_base62, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Random, base64, arginfo_phalcon_encryption_security_random_base64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Random, base64Safe, arginfo_phalcon_encryption_security_random_base64safe, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Random, bytes, arginfo_phalcon_encryption_security_random_bytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Random, hex, arginfo_phalcon_encryption_security_random_hex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Random, number, arginfo_phalcon_encryption_security_random_number, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Random, uuid1, arginfo_phalcon_encryption_security_random_uuid1, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Random, uuid, arginfo_phalcon_encryption_security_random_uuid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Random, base, arginfo_phalcon_encryption_security_random_base, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
