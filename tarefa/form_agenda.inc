<section>
	<?php
		$ed=false;
		if(!empty($_GET)){
			$age= bus_age($_GET["agenda"]);
			if(!empty($age)){
				$ed=true;
			}
		}
	?>

	<form action="form_agenda.php" method="post">
		<fieldset>
			<legend>novo agendamento</legend>
			
			<p>
				<label>codigo: </label>
				<input type="number" name="codigo" readonly="readonly"
					<?php
						if($ed){
							echo 'value="'. $age->codigo .'"';
						} else {
							$cod= bus_cod("agenda");
							echo 'value="'. $cod .'"';
						} 
					?>
				/>
			</p>

			<p>
				<label>Nome:</label>
				<input type="text" name="no" size="30"
					<?php
						if($ed){
							echo 'value="'. $age->nome .'"';
						}
					?>
				/>

				<label>E-mail</label>
				<input type="text" name="em"	size="30"
					<?php
						if($ed){
							echo 'value="'. $age->email .'"';
						}
					?>
				/>
			</p>

			<p>
				<label>Telefone:</label>
				<input type="text" name="tel" 
					<?php
						if($ed){
							echo 'value="'. $age->telefone .'"';
						}
					?>
				/>

				<label>data:</label>
				<input type="date" name="dt" 
					<?php
						if($ed){
							echo 'value="'. $age->data .'"';
						}
					?>
				/>
			</p>

			<p>
				<label>hora:</label>
				<input type="time" name="hr" 
					<?php
						if($ed){
							echo 'value="'. $age->hora .'"';
						}
					?>
				/>
			</p>

			<input type="hidden" name="modo"
				<?php
					if($ed){
						echo 'value="1"';
					} else {
						echo 'value="0"';
					}
				?>
			/>

			<br/><br/>
			<input type="submit" value="agendar"/>
			<br/><br/>
			<a href="agenda.php">ver agenda</a>
		</fieldset>
	</form>
</section>