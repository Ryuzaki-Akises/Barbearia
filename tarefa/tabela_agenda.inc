<section>
	<table class="tabela1" width="50%" border="1">
		<thead>
			<tr>
				<th>codigo</th>
				<th>Nome</th>
				<th>E-mail</th>
				<th>Telefone</th>
				<th>data</th>
				<th>hora</th>
				<th>editar</th>
				<th>excluir</th>
			</tr>
		</thead>
		<tbody>
			<?php
				lista_agenda()
			?>
		</tbody>
	</table>
	<br/><br/>
	<a href="form_agenda.php">novo agendamento</a>
</section>