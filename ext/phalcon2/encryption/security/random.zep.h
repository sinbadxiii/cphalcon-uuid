
extern zend_class_entry *phalcon2_encryption_security_random_ce;

ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Security_Random);

PHP_METHOD(Phalcon2_Encryption_Security_Random, uuid1);
PHP_METHOD(Phalcon2_Encryption_Security_Random, uuid3);
PHP_METHOD(Phalcon2_Encryption_Security_Random, uuid4);
PHP_METHOD(Phalcon2_Encryption_Security_Random, uuid5);
PHP_METHOD(Phalcon2_Encryption_Security_Random, uuid6);
PHP_METHOD(Phalcon2_Encryption_Security_Random, uuid);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon2_encryption_security_random_uuid1, 0, 0, Phalcon2\\Encryption\\Security\\Uuid, 0)
	ZEND_ARG_TYPE_INFO(0, uuid, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon2_encryption_security_random_uuid3, 0, 2, Phalcon2\\Encryption\\Security\\Uuid, 0)
	ZEND_ARG_INFO(0, ns)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon2_encryption_security_random_uuid4, 0, 0, Phalcon2\\Encryption\\Security\\Uuid, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon2_encryption_security_random_uuid5, 0, 2, Phalcon2\\Encryption\\Security\\Uuid, 0)
	ZEND_ARG_INFO(0, ns)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon2_encryption_security_random_uuid6, 0, 0, Phalcon2\\Encryption\\Security\\Uuid, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_random_uuid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon2_encryption_security_random_method_entry) {
	PHP_ME(Phalcon2_Encryption_Security_Random, uuid1, arginfo_phalcon2_encryption_security_random_uuid1, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_Random, uuid3, arginfo_phalcon2_encryption_security_random_uuid3, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_Random, uuid4, arginfo_phalcon2_encryption_security_random_uuid4, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_Random, uuid5, arginfo_phalcon2_encryption_security_random_uuid5, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_Random, uuid6, arginfo_phalcon2_encryption_security_random_uuid6, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Security_Random, uuid, arginfo_phalcon2_encryption_security_random_uuid, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
