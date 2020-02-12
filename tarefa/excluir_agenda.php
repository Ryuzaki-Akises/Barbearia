<?php
    $cod= $_GET["agenda"];
    if(file_exists("agendas.xml")){
        $xml= simplexml_load_file("agendas.xml");
        foreach($xml->children() as $age){
            if($age->codigo == $cod){
                unset($age[0]);
                file_put_contents("agendas.xml", $xml->asXML());
                header("Location: agenda.php");
            }
        }
    }
?>