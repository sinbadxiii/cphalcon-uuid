
extern zend_class_entry *phalcon2_encryption_security_binarybase_ce;

ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Security_BinaryBase);

PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, base58);
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, base62);
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, base64);
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, base64Safe);
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, bytes);
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, hex);
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, number);
PHP_METHOD(Phalcon2_Encryption_Security_BinaryBase, base);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_binarybase_base58, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_binarybase_base62, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_binarybase_base64, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_binarybase_base64safe, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, padding, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_binarybase_bytes, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_binarybase_hex, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_binarybase_number, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_binarybase_base, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, alphabet, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, base, IS_LONG, 0)
	ZEND_ARG_INFO(0, n)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon2_encryption_security_binarybase_method_entry) {
	PHP_ME(Phalcon2_Encryption_Security_BinaryBase, base58, arginfo_phalcon2_encryption_security_binarybase_base58, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_BinaryBase, base62, arginfo_phalcon2_encryption_security_binarybase_base62, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_BinaryBase, base64, arginfo_phalcon2_encryption_security_binarybase_base64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_BinaryBase, base64Safe, arginfo_phalcon2_encryption_security_binarybase_base64safe, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_BinaryBase, bytes, arginfo_phalcon2_encryption_security_binarybase_bytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_BinaryBase, hex, arginfo_phalcon2_encryption_security_binarybase_hex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_BinaryBase, number, arginfo_phalcon2_encryption_security_binarybase_number, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_BinaryBase, base, arginfo_phalcon2_encryption_security_binarybase_base, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
