
extern zend_class_entry *sparrow_0__closure_ce;

ZEPHIR_INIT_CLASS(sparrow_0__closure);

PHP_METHOD(sparrow_0__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_0__closure___invoke, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, address, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sparrow_0__closure_method_entry) {
	PHP_ME(sparrow_0__closure, __invoke, arginfo_sparrow_0__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
