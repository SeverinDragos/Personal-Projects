window.onload = function() {
	var Joy = document.querySelector("#ListaInsideOut li:first-child > span");
	if (Joy)
	Joy.onclick = AddPozaJoy;
	var Anger = document.querySelector("#ListaInsideOut li:nth-child(2) > span");
	if (Anger)
	Anger.onclick = AddPozaAnger;
	var Sadness = document.querySelector("#ListaInsideOut li:last-child > span");
	if (Sadness)
	Sadness.onclick = AddPozaSadness;
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