window.onload = function() {
	var Buton = document.getElementById("SurveyButton");
	if (Buton)
	Buton.onclick = TakeSurvey;
	var colectie = document.getElementsByTagName("aside");
	var sectiune = document.querySelector("#Survey section");
	sectiune.ondragover = function(e) {e.preventDefault();}
	var fav = document.getElementById("favorite");
	fav.ondragover = function(e) {e.preventDefault();}
	
	for (let i = 0; i < colectie.length; i++) {
		colectie[i].stilInitial = window.getComputedStyle(colectie[i]);
		colectie[i].draggable = true;
		colectie[i].id = i;
		colectie[i].ondragstart = function(e) {
												e.dataTransfer.setData("id", colectie[i].id);
												}
	}
	colectie[0].style.color = "purple";
	colectie[1].style.color = "#33ccff";
	colectie[2].style.color = "green";
	colectie[3].style.color = "yellow";
	fav.ondrop = function(e) {
								e.preventDefault();
								var data = e.dataTransfer.getData("id");
								var x = document.getElementById(data);
								e.target.appendChild(x);
								x.style.color = x.stilInitial.color;
								e.target.ondrop = function(e) {e.preventDefault();}
							}
	if (localStorage.ultimaOra != undefined) {
		var ceas = document.getElementById("ceas");
		ceas.innerHTML += localStorage.ultimaOra + ":" + localStorage.ultimulMinut + ":" + localStorage.ultimaSecunda;
	}
	var d = new Date;
	localStorage.ultimaOra = d.getHours();
	localStorage.ultimulMinut = d.getMinutes();
	localStorage.ultimaSecunda = d.getSeconds();
}

function TakeSurvey() {
	var sum = 0;
	var Coco = document.querySelector("#Survey input:nth-of-type(1)");
	if (Coco.checked == true)	sum++;
	var Frozen = document.querySelector("#Survey input:nth-of-type(2)");
	if (Frozen.checked == true)	sum++;
	var InsideOut = document.querySelector("#Survey input:nth-of-type(3)");
	if (InsideOut.checked == true)	sum++;
	var Zootopia = document.querySelector("#Survey input:nth-of-type(4)");
	if (Zootopia.checked == true)	sum++;
	
	switch(sum) {
		case 0:
		alert("You`re not much of a Disney fan, are you? :(");
		break;
		case 1:
		alert("You`re an occasional Disney fan!");
		break;
		case 2:
		alert("You`re a Disney fan in your freetime!");
		break;
		case 3:
		alert("You`ve got one Disney movie to catch up on!");
		break;
		case 4:
		alert("Woah! You`re a true Disney fan!");
		break;
	}
}