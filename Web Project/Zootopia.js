window.onload = function() {
	var Judy = document.querySelector("#ListaZootopia li:first-child > span");
	if (Judy)
	Judy.onclick = AddPozaJudy;
	var Nick = document.querySelector("#ListaZootopia li:nth-child(2) > span");
	if (Nick)
	Nick.onclick = AddPozaNick;
	var MayorLionheart = document.querySelector("#ListaZootopia li:last-child > span");
	if (MayorLionheart)
	MayorLionheart.onclick = AddPozaMayorLionheart;

	var divZootopia = document.getElementById("Zootopia");
	divZootopia.children[8].onkeypress = pacaleala;
	
	var buton = document.querySelector("#Zootopia span input");
	buton.onclick = function() { alert("What`s the point of clicking \"Done\" if you don`t know the secret code?");}
}

function pacaleala(e) {
	var span = document.createElement("span");
	span.style.visibility = "hidden";
	span.innerHTML += e.key;
	this.value = "Keep trying!";
	e.preventDefault();
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