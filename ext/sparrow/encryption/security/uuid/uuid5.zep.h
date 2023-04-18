
extern zend_class_entry *sparrow_encryption_security_uuid_uuid5_ce;

ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid_Uuid5);

PHP_METHOD(Sparrow_Encryption_Security_Uuid_Uuid5, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_encryption_security_uuid_uuid5___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, ns, Sparrow\\Encryption\\Security\\Uuid, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sparrow_encryption_security_uuid_uuid5_method_entry) {
	PHP_ME(Sparrow_Encryption_Security_Uuid_Uuid5, __construct, arginfo_sparrow_encryption_security_uuid_uuid5___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
