
extern zend_class_entry *phalcon2_encryption_security_uuid_randomnodeprovider_ce;

ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Security_Uuid_RandomNodeProvider);

PHP_METHOD(Phalcon2_Encryption_Security_Uuid_RandomNodeProvider, getNode);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_uuid_randomnodeprovider_getnode, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon2_encryption_security_uuid_randomnodeprovider_method_entry) {
	PHP_ME(Phalcon2_Encryption_Security_Uuid_RandomNodeProvider, getNode, arginfo_phalcon2_encryption_security_uuid_randomnodeprovider_getnode, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
