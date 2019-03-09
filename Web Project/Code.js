window.onload = function main() {
///Coco
	var Miguel = document.querySelector("#ListaCoco li:first-child > span");
	if (Miguel)
	Miguel.onclick = AddPozaMiguel;
	var Dante = document.querySelector("#ListaCoco li:nth-child(2) > span");
	if (Dante)
	Dante.onclick = AddPozaDante;
	var Ernesto = document.querySelector("#ListaCoco li:last-child > span");
	if (Ernesto)
	Ernesto.onclick = AddPozaErnesto;
///Frozen
	var Elsa = document.querySelector("#ListaFrozen li:first-child > span");
	if (Elsa)
	Elsa.onclick = AddPozaElsa;
	var Olaf = document.querySelector("#ListaFrozen li:nth-child(2) > span");
	if (Olaf)
	Olaf.onclick = AddPozaOlaf;
	var Anna = document.querySelector("#ListaFrozen li:last-child > span");
	if (Anna)
	Anna.onclick = AddPozaAnna;
///Inside Out
	var Joy = document.querySelector("#ListaInsideOut li:first-child > span");
	if (Joy)
	Joy.onclick = AddPozaJoy;
	var Anger = document.querySelector("#ListaInsideOut li:nth-child(2) > span");
	if (Anger)
	Anger.onclick = AddPozaAnger;
	var Sadness = document.querySelector("#ListaInsideOut li:last-child > span");
	if (Sadness)
	Sadness.onclick = AddPozaSadness;
///Zootopia
	var Judy = document.querySelector("#ListaZootopia li:first-child > span");
	if (Judy)
	Judy.onclick = AddPozaJudy;
	var Nick = document.querySelector("#ListaZootopia li:nth-child(2) > span");
	if (Nick)
	Nick.onclick = AddPozaNick;
	var MayorLionheart = document.querySelector("#ListaZootopia li:last-child > span");
	if (MayorLionheart)
	MayorLionheart.onclick = AddPozaMayorLionheart;
///Survey
	var Buton = document.getElementById("SurveyButton");
	if (Buton)
	Buton.onclick = TakeSurvey;
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

function AddPozaMiguel() {
	var div = document.getElementById("Coco");
	var poza = document.createElement("img");
	poza.src = "Miguel.jpg";
	poza.style.height = "20%";
	poza.style.width = "20%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaMiguel() {
		div.removeChild(poza);
	}
}

function AddPozaDante() {
	var div = document.getElementById("Coco");
	var poza = document.createElement("img");
	poza.src = "Dante.jpg";
	poza.style.height = "20%";
	poza.style.width = "20%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaDante() {
		div.removeChild(poza);
	}
}

function AddPozaErnesto() {
	var div = document.getElementById("Coco");
	var poza = document.createElement("img");
	poza.src = "Ernesto.jpg";
	poza.style.height = "18%";
	poza.style.width = "18%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaErnesto() {
		div.removeChild(poza);
	}
}

function AddPozaElsa() {
	var div = document.getElementById("Frozen");
	var poza = document.createElement("img");
	poza.src = "Elsa.jpg";
	poza.style.height = "20%";
	poza.style.width = "20%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaElsa() {
		div.removeChild(poza);
	}
}

function AddPozaOlaf() {
	var div = document.getElementById("Frozen");
	var poza = document.createElement("img");
	poza.src = "Olaf.jpg";
	poza.style.height = "20%";
	poza.style.width = "20%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaOlaf() {
		div.removeChild(poza);
	}
}

function AddPozaAnna() {
	var div = document.getElementById("Frozen");
	var poza = document.createElement("img");
	poza.src = "Anna.jpg";
	poza.style.height = "20%";
	poza.style.width = "20%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaAnna() {
		div.removeChild(poza);
	}
}

function AddPozaJoy() {
	var div = document.getElementById("InsideOut");
	var poza = document.createElement("img");
	poza.src = "Joy.jpg";
	poza.style.height = "20%";
	poza.style.width = "20%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaJoy() {
		div.removeChild(poza);
	}
}

function AddPozaAnger() {
	var div = document.getElementById("InsideOut");
	var poza = document.createElement("img");
	poza.src = "Anger.jpg";
	poza.style.height = "20%";
	poza.style.width = "20%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaAnger() {
		div.removeChild(poza);
	}
}

function AddPozaSadness() {
	var div = document.getElementById("InsideOut");
	var poza = document.createElement("img");
	poza.src = "Sadness.jpg";
	poza.style.height = "20%";
	poza.style.width = "20%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaSadness() {
		div.removeChild(poza);
	}
}

function AddPozaJudy() {
	var div = document.getElementById("Zootopia");
	var poza = document.createElement("img");
	poza.src = "Judy.jpeg";
	poza.style.height = "21%";
	poza.style.width = "21%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaJudy() {
		div.removeChild(poza);
	}
}

function AddPozaNick() {
	var div = document.getElementById("Zootopia");
	var poza = document.createElement("img");
	poza.src = "Nick.jpg";
	poza.style.height = "24%";
	poza.style.width = "24%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaNick() {
		div.removeChild(poza);
	}
}

function AddPozaMayorLionheart() {
	var div = document.getElementById("Zootopia");
	var poza = document.createElement("img");
	poza.src = "MayorLionheart.jpg";
	poza.style.height = "20%";
	poza.style.width = "20%";
	div.appendChild(poza);
	poza.onclick = function RemovePozaMayorLionheart() {
		div.removeChild(poza);
	}
}