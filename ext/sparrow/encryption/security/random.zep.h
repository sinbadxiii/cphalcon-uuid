
extern zend_class_entry *sparrow_encryption_security_random_ce;

ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Random);

PHP_METHOD(Sparrow_Encryption_Security_Random, uuid1);
PHP_METHOD(Sparrow_Encryption_Security_Random, uuid3);
PHP_METHOD(Sparrow_Encryption_Security_Random, uuid4);
PHP_METHOD(Sparrow_Encryption_Security_Random, uuid5);
PHP_METHOD(Sparrow_Encryption_Security_Random, uuid6);
PHP_METHOD(Sparrow_Encryption_Security_Random, uuid);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_random_uuid1, 0, 0, Sparrow\\Encryption\\Security\\Uuid, 0)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_random_uuid3, 0, 2, Sparrow\\Encryption\\Security\\Uuid, 0)
	ZEND_ARG_INFO(0, ns)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_random_uuid4, 0, 0, Sparrow\\Encryption\\Security\\Uuid, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_random_uuid5, 0, 2, Sparrow\\Encryption\\Security\\Uuid, 0)
	ZEND_ARG_INFO(0, ns)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_random_uuid6, 0, 0, Sparrow\\Encryption\\Security\\Uuid, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sparrow_encryption_security_random_uuid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sparrow_encryption_security_random_method_entry) {
	PHP_ME(Sparrow_Encryption_Security_Random, uuid1, arginfo_sparrow_encryption_security_random_uuid1, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Encryption_Security_Random, uuid3, arginfo_sparrow_encryption_security_random_uuid3, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Encryption_Security_Random, uuid4, arginfo_sparrow_encryption_security_random_uuid4, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Encryption_Security_Random, uuid5, arginfo_sparrow_encryption_security_random_uuid5, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Encryption_Security_Random, uuid6, arginfo_sparrow_encryption_security_random_uuid6, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Encryption_Security_Random, uuid, arginfo_sparrow_encryption_security_random_uuid, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
