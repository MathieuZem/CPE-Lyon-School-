$(function () {
    $("#nav").load("annexes.html #haut");
    $("#basdepage").load("annexes.html #basdepage");
    $("#return").load("annexes.html #remonter");
});

jQuery(function () {
    $(function () {
        $(window).scroll(function () {
            if ($(this).scrollTop() > 200) {
                $("#remonter").css("right", "10px");
            } else {
                $("#remonter").removeAttr("style");
            }

        });
    });
});

function openForm() {
    document.getElementById("popup").style.display = "block";
};

function clearPanier() {

};

/*
let portes = [
    { gamme: "Porte Dooritos", prix: "150€", lien:"../HTML/Personnalisation.html?1", image: "../image/Porte Doritos/porte-dooritos2.png", alt:"Porte Dooritos"},
    { gamme: "Porte Classique", prix: "30€", lien:"../HTML/Personnalisation.html?2", image: "../image/Porte Classique/porte-classique2.png", alt:"Porte Classique"},
    { gamme: "Porte Coulissante", prix: "50€", lien:"../HTML/Personnalisation.html?3", image: "../image/Porte Coulissante/porte-coulissante2.png", alt:"Porte Coulissante"},
    { gamme: "Porte Blinde", prix: "250€", lien:"../HTML/Personnalisation.html?4", image: "../image/Porte Blinde/porte-blinde2.png", alt:"Porte Blinde"},
    { gamme: "Porte Fenêtre", prix: "110€", lien:"../HTML/Personnalisation.html?5", image: "../image/Porte Fenêtre/porte-fenetre2.png", alt:"Porte Fenêtre"},
    { gamme: "Porte de Garage", prix: "180€", lien:"../HTML/Personnalisation.html?6", image: "../image/Porte de Garage/porte-de-garage2.png", alt:"Porte de Garage"},
    { gamme: "Porte Coupe-Feu", prix: "200€", lien:"../HTML/Personnalisation.html?7", image: "../image/Porte Coupe-Feu/porte-coupe-feu.jpg", alt:"Porte Coupe-Feu"},
];
*/

fetch("../JS/DataBase.json")
    .then(function (response) {
        return response.json();
    })
    .then(function (json) {
        /* console.log(json["portes"]["gamme"]); */
        // ou
        console.log(json.porte.nom);

        let template = document.querySelector("#gamme");
        let Porte = json['porte']

        let i = 0;
        for (const porte of Porte) {
            let clone = document.importNode(template.content, true);
            newContent = clone.firstElementChild.innerHTML
                .replace(/{{IndexPagePerso}}/g, i)
                .replace(/{{LienIMG}}/g, porte.image)
                .replace(/{{alt}}/g, porte.alt)
                .replace(/{{Prix}}/g, porte.prix);
            clone.firstElementChild.innerHTML = newContent
            template.parentNode.appendChild(clone);
            i++;
        }
    });

class Porte {
    constructor(nom, prix, imagePrevisualisation, personnalisation) {
        this.nom = nom;
        this.prix = prix;
        this.imagePrevisualisation = imagePrevisualisation;
        this.personnalisation = personnalisation;
    }
    get_nom() { return this.nom; }
    get_prix() { return this.prix; }
    get_imagePrevisualisation() { return this.imagePrevisualisation; }
    get_personnalisation() { return this.personnalisation; }

}

class LesPersonnalisations {
    constructor(nom, prix, lien) {
        this.nom = nom;
        this.prix = prix;
        this.lien = lien;
    }
    get_nom() { return this.nom; }
    get_prix() { return this.prix; }
    get_prix() { return this.lien; }
}



$.get("../JS/DataBase.json", function (data) {

    let tableau = [];
    for (var json_porte of data["porte"]) {
        tableau.push(Object.assign(new Porte(), json_porte));
    };


    let porte_id = new URLSearchParams(window.location.search).get("id");


    if (porte_id != null) {
        document.getElementById("canvas").style.background = "url(" + tableau[porte_id].get_imagePrevisualisation() + ") center center no-repeat";
        document.getElementById("PrixPerso").innerHTML = tableau[porte_id].get_prix()
        document.getElementById("NomPortePerso").innerHTML = tableau[porte_id].get_nom()

        console.log(tableau[porte_id].get_imagePrevisualisation());
    };



});

function remplir() {
    let str = document.getElementById("imagePrevisualisation").innerHTML;
};



$.get("../JS/DataBase.json", function (data) {

    let tableauParaPerso = [];
    for (var json_porte_personnalisation of data["porte"]) {
        tableauParaPerso.push(Object.assign(new LesPersonnalisations(), json_porte_personnalisation));
    };


    let Personnalisation_id = new URLSearchParams(window.location.search).get("id");

    let i = 0

    if (i=0) {
        document.getElementById("canvas").style.background = "url(" + tableau[porte_id].get_imagePrevisualisation() + ") center center no-repeat";
        document.getElementById("PrixPerso").innerHTML = tableau[porte_id].get_prix()
        document.getElementById("NomPortePerso").innerHTML = tableau[porte_id].get_nom()


        console.log(tableau[porte_id].get_imagePrevisualisation());
    };



});

fetch("../JS/DataBase.json")
    .then(function (response) {
        return response.json();
    })
    .then(function (json) {

        let template = document.querySelector("#personnalisation");
        let PPersonnalisation = json.porte.personnalisation.Coloris;

        let p = 0;
        for (const perso of PPersonnalisation) {

            let clone = document.importNode(template.content, true);
            newContent = clone.firstElementChild.innerHTML
                .replace(/{{LienImgPerso}}/g, perso.Coloris.lien + p)
                .replace(/{{NomPerson}}/g, perso.Coloris.Colo1 + p)
                .replace(/{{PrixPerso}}/g, perso.Coloris.prix + p)
            clone.firstElementChild.innerHTML = newContent
            template.parentNode.appendChild(clone);
            p++;
        }
    });