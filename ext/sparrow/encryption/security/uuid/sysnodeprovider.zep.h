
extern zend_class_entry *sparrow_encryption_security_uuid_sysnodeprovider_ce;

ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid_SysNodeProvider);

PHP_METHOD(Sparrow_Encryption_Security_Uuid_SysNodeProvider, getNode);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sparrow_encryption_security_uuid_sysnodeprovider_getnode, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sparrow_encryption_security_uuid_sysnodeprovider_method_entry) {
	PHP_ME(Sparrow_Encryption_Security_Uuid_SysNodeProvider, getNode, arginfo_sparrow_encryption_security_uuid_sysnodeprovider_getnode, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
