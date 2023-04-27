
extern zend_class_entry *sparrow_encryption_security_uuid_uuid1_ce;

ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid_Uuid1);

PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid1, __construct);
PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid1, getDateTime);
PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid1, getNode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_encryption_security_uuid_uuid1___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, time, \\DateTimeInterface, 1)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_uuid_uuid1_getdatetime, 0, 0, \\DateTimeImmutable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sparrow_encryption_security_uuid_uuid1_getnode, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sparrow_encryption_security_uuid_uuid1_method_entry) {
	PHP_ME(Sparrow_Encryption_Security_Uuid_Uuid1, __construct, arginfo_sparrow_encryption_security_uuid_uuid1___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Sparrow_Encryption_Security_Uuid_Uuid1, getDateTime, arginfo_sparrow_encryption_security_uuid_uuid1_getdatetime, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Encryption_Security_Uuid_Uuid1, getNode, arginfo_sparrow_encryption_security_uuid_uuid1_getnode, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
