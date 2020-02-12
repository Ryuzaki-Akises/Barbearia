<!DOCTYPE html>
<html lang="pt-BR">
	<head>
		<head>
		<meta charset="utf-8">
		<title>barbearia</title>
		<link rel="stylesheet" href="estilos.css">
	</head>
	</head>
	<body>
		<?php
			include "funcoes.inc";
			include "cabecalho.inc";
			include "menu.inc";
			if(file_exists("agendas.xml")){
				include "mensagem.inc";
			}
			include "rodape.inc";
		?>	
	</body>
</html>		
		