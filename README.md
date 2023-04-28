# Phalcon Uuid

The library allows you to generate uuid 1-6 versions (for now).

## Versions 

PHP 8.x

## Install

```
git clone https://github.com/sinbadxiii/cphalcon-uuid
cd cphalcon-uuid/ext
sudo ./install
```

include php ext `phalcon_uuid` in your PHP

```shell
php -m

...
pdo_mysql
pdo_sqlite
phalcon
phalcon_uuid
Phar
posix
...
```

Example:

```php 
$random = new \Sparrow\Encryption\Security\Random();

//version 1
$random->uuid1(); //01e67d70-ddc8-11ed-ab2f-64a0807c6238
$random->uuid1(); //0c535000-ddc8-11ed-b96b-64a0807c6238
$random->uuid1(); //0d8ccf70-ddc8-11ed-a1c5-64a0807c6238

//version 3
$random->uuid3($uuid->uuid1(), "name") //c3410c85-6317-3d54-ba9e-d515be361767
$random->uuid3($uuid->uuid1(), "name") //6f3cede7-be2f-31f3-a278-5fee83616421
$random->uuid3($uuid->uuid1(), "name") //2a83e5e9-98e2-3584-ae41-2baeb33f8664

//version 4
$random->uuid4() //f52d2877-708f-4a2e-9cfb-0ca61a379e14
$random->uuid4() //e0170f8a-c263-4656-98c1-450553a8d48f
$random->uuid4() //0d5957c3-3506-45f5-b6dd-3d27c439ef81

//version 5
$uuid->uuid5($uuid->uuid4(), "name") //e2638379-8788-54d0-aa16-c2456941dddc
$uuid->uuid5($uuid->uuid4(), "name") //48edad3f-881b-568d-b998-5c8c3ed20728
$uuid->uuid5($uuid->uuid4(), "name") //cafcfaf8-e83f-5e7e-9a23-7039010f5168

//version 6
//first 
$random->uuid6(); //1ede4ea1-7725-6670-916f-f9e288af019f 
$random->uuid6(); //1ede4ea1-7725-6770-be3c-f9e288af019f
$random->uuid6(); //1ede4ea1-7725-67e0-8837-f9e288af019f
...
//second
$random->uuid6(); //1ede4eac-294b-6fe0-bedf-313f2e13333a
$random->uuid6(); //1ede4eac-294c-6120-a6fb-313f2e13333a
$random->uuid6(); //1ede4eac-294c-61a0-9490-313f2e13333a
```



