<!DOCTYPE html>
<html lang="pt-BR">
	<head>
		<meta charset="utf-8">
		<title>barbearia</title>
		<link rel="stylesheet" href="estilos.css">
	</head>
	<body>
		<?php
			include "funcoes.inc";
			include "cabecalho.inc";
			include "menu.inc";
			if(empty($_POST)){
				include "form_agenda.inc";
			}else{
				ler_agenda();
			}
			include "rodape.inc";
		?>	
	</body>
</html>





