<?php
	function bus_cod($ent){
		if(file_exists("seq_cod.xml")){
			$xml= simplexml_load_file("seq_cod.xml");
			switch($ent){
				case "agenda": return $xml->agenda;
			}
		} else {
			$xml= '<?xml version="1.0" encoding="UTF-8" ?>
					<codigos>
						<agenda>1</agenda>
					</codigos>';
			file_put_contents("seq_cod.xml", $xml);
			return 1;
		}
	}

	function atual_cod($ent){
		if(file_exists("seq_cod.xml")){
			$xml= simplexml_load_file("seq_cod.xml");
			switch($ent){
				case "agenda": $xml->agenda++; break;
			}
			file_put_contents("seq_cod.xml", $xml->asXML());
		} 
	}

	function ler_agenda(){
		$cod= $_POST["codigo"];
		$no = $_POST["no"];
		$em = $_POST["em"];
		$tel = $_POST["tel"];
		$dt = $_POST["dt"];
		$hr = $_POST["hr"];
		$modo= $_POST["modo"];

		if($modo == 0){
			if(!file_exists("agendas.xml")){
				$xml= '<?xml version="1.0" encoding="UTF-8" ?>
						<agendas>
							<agenda>
								<codigo>'. $cod .'</codigo>
								<nome>'. $no .'</nome>
								<email>'. $em .'</email>
								<telefone>'. $tel .'</telefone>
								<data>'. $dt .'</data>	
								<hora>'. $hr .'</hora>	
							</agenda>
						</agendas>';
				file_put_contents("agendas.xml", $xml);
				atual_cod("agenda");
			} else {
				$xml= simplexml_load_file("agendas.xml");
				$age= $xml->addChild("agenda");
				$age->addChild("codigo", $cod);
				$age->addChild("nome", $no);
				$age->addChild("email", $em);
				$age->addChild("telefone", $tel);
				$age->addChild("data", $dt);
				$age->addChild("hora", $hr);
				file_put_contents("agendas.xml", $xml->asXML());
				atual_cod("agenda");
			}
			
			header("Location: recebe_agenda.php");
			
		} else {
			$xml= simplexml_load_file("agendas.xml");
			foreach($xml->children() as $age){
				if($age->codigo == $cod){
					$age->nome = $no;
					$age->email = $em;
					$age->telefone = $tel;
					$age->data = $dt;
					$age->hora = $hr;
				}
			}
			file_put_contents("agendas.xml", $xml->asXML());
			echo "<section>
					<h2>agendamento editado com sucesso.</h2>
				</section>";
		}
	}

	function bus_age($cod){
		if(file_exists("agendas.xml")){
			$xml= simplexml_load_file("agendas.xml");
			foreach($xml->children() as $age){
				if($age->codigo == $cod){
					return $age;
				}
			}
		}
	}

	function lista_agenda(){
		$xml= simplexml_load_file("agendas.xml");
		foreach($xml->children() as $age){
			echo "
				<tr>
					<td>$age->codigo</td>
					<td>$age->nome</td>
					<td>$age->email</td>
					<td>$age->telefone</td>
					<td>$age->data</td>
					<td>$age->hora</td>
					<td>
						<a href=\"form_agenda.php?agenda=$age->codigo\">editar</a>
					</td>
					<td>
						<a href=\"excluir_agenda.php?agenda=$age->codigo\">excluir</a>
					</td>
				</tr>";
		}
	}
?>