
extern zend_class_entry *phalcon2_encryption_security_jwt_signer_abstractsigner_ce;

ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Security_JWT_Signer_AbstractSigner);

PHP_METHOD(Phalcon2_Encryption_Security_JWT_Signer_AbstractSigner, getAlgorithm);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_security_jwt_signer_abstractsigner_getalgorithm, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon2_encryption_security_jwt_signer_abstractsigner_method_entry) {
	PHP_ME(Phalcon2_Encryption_Security_JWT_Signer_AbstractSigner, getAlgorithm, arginfo_phalcon2_encryption_security_jwt_signer_abstractsigner_getalgorithm, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
