
extern zend_class_entry *phalcon2_encryption_security_uuid_uuid4_ce;

ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Security_Uuid_Uuid4);

PHP_METHOD(Phalcon2_Encryption_Security_Uuid_Uuid4, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon2_encryption_security_uuid_uuid4___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, uuid, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon2_encryption_security_uuid_uuid4_method_entry) {
	PHP_ME(Phalcon2_Encryption_Security_Uuid_Uuid4, __construct, arginfo_phalcon2_encryption_security_uuid_uuid4___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
