window.onload = function() {
	var Miguel = document.querySelector("#ListaCoco li:first-child > span");
	if (Miguel)
	Miguel.onclick = AddPozaMiguel;
	var Dante = document.querySelector("#ListaCoco li:nth-child(2) > span");
	if (Dante)
	Dante.onclick = AddPozaDante;
	var Ernesto = document.querySelector("#ListaCoco li:last-child > span");
	if (Ernesto)
	Ernesto.onclick = AddPozaErnesto;

	var span = document.querySelector("#Coco article span");
	var MyWindow;
	span.onclick = function() { DeschideYoutube(); span.onclick = InchideYoutube;}
}

function DeschideYoutube() {
	MyWindow = window.open("https://www.youtube.com/watch?v=Ga6RYejo6Hk"); 
}

function InchideYoutube() {
	MyWindow.close();
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