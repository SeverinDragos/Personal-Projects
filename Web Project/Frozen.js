window.onload = function() {
	var Elsa = document.querySelector("#ListaFrozen li:first-child > span");
	if (Elsa)
	Elsa.onclick = AddPozaElsa;
	var Olaf = document.querySelector("#ListaFrozen li:nth-child(2) > span");
	if (Olaf)
	Olaf.onclick = AddPozaOlaf;
	var Anna = document.querySelector("#ListaFrozen li:last-child > span");
	if (Anna)
	Anna.onclick = AddPozaAnna;

	var Frozenlogo = document.getElementById("FrozenLogo");
	Frozenlogo.onclick = function(){setInterval(DeclanseazaPloaia, 1000);}
}

function AddPozaElsa() {
	var div = document.getElementById("Frozen");
	var poza = document.createElement("img");
	poza.src = "Elsa.jpg";
	poza.classList.add("pozacreata");
	div.appendChild(poza);
	poza.onclick = function RemovePozaElsa() {
		div.removeChild(poza);
	}
}

function AddPozaOlaf() {
	var div = document.getElementById("Frozen");
	var poza = document.createElement("img");
	poza.src = "Olaf.jpg";
	poza.classList.add("pozacreata");
	div.appendChild(poza);
	poza.onclick = function RemovePozaOlaf() {
		div.removeChild(poza);
	}
}

function AddPozaAnna() {
	var div = document.getElementById("Frozen");
	var poza = document.createElement("img");
	poza.src = "Anna.jpg";
	poza.className = "pozacreata";
	div.appendChild(poza);
	poza.onclick = function RemovePozaAnna() {
		div.removeChild(poza);
	}
}

function DeclanseazaPloaia() {
	var body = document.querySelector("body");
	var fulg = document.createElement("img");
	fulg.xnou = 0;
	fulg.src = "fulg.png";
	fulg.style.position = "absolute";
	fulg.style.top = "0px";
	fulg.style.left = Math.floor((Math.random() * 1000) + 1) + "px";
	fulg.style.width = Math.floor((Math.random() * 350) + 1) + "px";
	fulg.style.height = fulg.style.width;
	fulg.proprietate = parseInt(fulg.style.width);
	body.appendChild(fulg);
	fulg.t = setInterval(function(scadere) {
		fulg.xnou += 5; 
		fulg.style.top = fulg.xnou + "px"; 
		fulg.proprietate -= scadere; 
		fulg.style.width = fulg.proprietate + "px";
		fulg.style.height = fulg.proprietate + "px";
		if (fulg.proprietate <= 0)	{
			body.removeChild(fulg);
			clearInterval(fulg.t);
		}
		},100, Math.random() * 3);
		
	fulg.onclick = function(e) {clearInterval(fulg.t); body.removeChild(fulg); e.stopPropagation();}
}