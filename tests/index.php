<?php

declare(strict_types=1);

$random = new \Sparrow\Encryption\Security\Random();

$data = [];

for ($i=0; $i <=100000; $i++) {

    $uuid = (string)$random->uuid1();

    if (isset($data[$uuid])) {
        $data[$uuid] += 1;
    } else {
        $data[$uuid] = 1;
    }
    echo $uuid . "\r\n";
}

for ($i=0; $i <=100000; $i++) {

    $uuid = (string)$random->uuid3($random->uuid1(), "name");

    if (isset($data[$uuid])) {
        $data[$uuid] += 1;
    } else {
        $data[$uuid] = 1;
    }
    echo $uuid . "\r\n";
}

for ($i=0; $i <=100000; $i++) {

    $uuid = (string)$random->uuid4();

    if (isset($data[$uuid])) {
        $data[$uuid] += 1;
    } else {
        $data[$uuid] = 1;
    }
    echo $uuid . "\r\n";
}

for ($i=0; $i <=100000; $i++) {

    $uuid = (string)$random->uuid5($random->uuid4(), "name");

    if (isset($data[$uuid])) {
        $data[$uuid] += 1;
    } else {
        $data[$uuid] = 1;
    }
    echo $uuid . "\r\n";
}

for ($i=0; $i <=100000; $i++) {

    $uuid = (string)$random->uuid6();

    if (isset($data[$uuid])) {
        $data[$uuid] += 1;
    } else {
        $data[$uuid] = 1;
    }
    echo $uuid . "\r\n";
}

foreach ($data as $uuid => $value) {

    if ($value > 1) {
        die($uuid);
    }
}
