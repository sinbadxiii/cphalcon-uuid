
extern zend_class_entry *phalcon2_encryption_security_jwt_token_abstractitem_ce;

ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Security_JWT_Token_AbstractItem);

PHP_METHOD(Phalcon2_Encryption_Security_JWT_Token_AbstractItem, getEncoded);
zend_object *zephir_init_properties_Phalcon2_Encryption_Security_JWT_Token_AbstractItem(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_jwt_token_abstractitem_getencoded, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon2_encryption_security_jwt_token_abstractitem_zephir_init_properties_phalcon2_encryption_security_jwt_token_abstractitem, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon2_encryption_security_jwt_token_abstractitem_method_entry) {
	PHP_ME(Phalcon2_Encryption_Security_JWT_Token_AbstractItem, getEncoded, arginfo_phalcon2_encryption_security_jwt_token_abstractitem_getencoded, ZEND_ACC_PUBLIC)
	PHP_FE_END
};