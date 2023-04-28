PHP_ARG_ENABLE(phalcon_uuid, whether to enable phalcon_uuid, [ --enable-phalcon_uuid   Enable Phalcon_uuid])

if test "$PHP_PHALCON_UUID" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PHALCON_UUID_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PHALCON_UUID, 1, [Whether you have Phalcon_uuid])
	phalcon_uuid_sources="phalcon_uuid.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c sparrow/encryption/crypt/padding/padinterface.zep.c
	sparrow/encryption/security/binarybase.zep.c
	sparrow/encryption/security/uuid.zep.c
	sparrow/encryption/security/uuid/nodeproviderinterface.zep.c
	sparrow/encryption/security/uuid/timebaseduidinterface.zep.c
	sparrow/encryption/crypt/cryptinterface.zep.c
	sparrow/encryption/crypt/exception/exception.zep.c
	sparrow/encryption/crypt.zep.c
	sparrow/encryption/crypt/exception/mismatch.zep.c
	sparrow/encryption/crypt/padding/ansi.zep.c
	sparrow/encryption/crypt/padding/iso10126.zep.c
	sparrow/encryption/crypt/padding/isoiek.zep.c
	sparrow/encryption/crypt/padding/noop.zep.c
	sparrow/encryption/crypt/padding/pkcs7.zep.c
	sparrow/encryption/crypt/padding/space.zep.c
	sparrow/encryption/crypt/padding/zero.zep.c
	sparrow/encryption/security.zep.c
	sparrow/encryption/security/exception.zep.c
	sparrow/encryption/security/random.zep.c
	sparrow/encryption/security/uuid/randomnodeprovider.zep.c
	sparrow/encryption/security/uuid/sysnodeprovider.zep.c
	sparrow/encryption/security/uuid/uuid1.zep.c
	sparrow/encryption/security/uuid/uuid3.zep.c
	sparrow/encryption/security/uuid/uuid4.zep.c
	sparrow/encryption/security/uuid/uuid5.zep.c
	sparrow/encryption/security/uuid/uuid6.zep.c
	sparrow/0__closure.zep.c "
	PHP_NEW_EXTENSION(phalcon_uuid, $phalcon_uuid_sources, $ext_shared,, )
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	for dir in "sparrow sparrow/encryption sparrow/encryption/crypt sparrow/encryption/crypt/exception sparrow/encryption/crypt/padding sparrow/encryption/security sparrow/encryption/security/uuid"; do
		PHP_ADD_BUILD_DIR([$ext_builddir/$dir])
	done
	PHP_SUBST(PHALCON_UUID_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon_uuid], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon_uuid], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/phalcon_uuid], [php_PHALCON_UUID.h])

fi
