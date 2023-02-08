console.log("coucou")

let portes = [
    { gamme: "Porte Dooritos", prix: "150€", lien:"../HTML/Personnalisation.html?1", image: "../image/Porte Doritos/porte-dooritos2.png", alt:"Porte Dooritos"},
    { gamme: "Porte Classique", prix: "30€", lien:"../HTML/Personnalisation.html?2", image: "../image/Porte Classique/porte-classique2.png", alt:"Porte Classique"},
    { gamme: "Porte Coulissante", prix: "50€", lien:"../HTML/Personnalisation.html?3", image: "../image/Porte Coulissante/porte-coulissante2.png", alt:"Porte Coulissante"},
    { gamme: "Porte Blinde", prix: "250€", lien:"../HTML/Personnalisation.html?4", image: "../image/Porte Blinde/porte-blinde2.png", alt:"Porte Blinde"},
    { gamme: "Porte Fenêtre", prix: "110€", lien:"../HTML/Personnalisation.html?5", image: "../image/Porte Fenêtre/porte-fenetre2.png", alt:"Porte Fenêtre"},
    { gamme: "Porte de Garage", prix: "180€", lien:"../HTML/Personnalisation.html?6", image: "../image/Porte de Garage/porte-de-garage2.png", alt:"Porte de Garage"},
    { gamme: "Porte Coupe-Feu", prix: "200€", lien:"../HTML/Personnalisation.html?7", image: "../image/Porte Coupe-Feu/porte-coupe-feu.jpg", alt:"Porte Coupe-Feu"},
];

let template = document.querySelector("#gamme");

for (const porte of portes) { 
    let clone = document.importNode(template.content, true);
    newContent = clone.firstElementChild.innerHTML
    .replace(/{{LienPagePerso}}/g, porte.lien)
    .replace(/{{LienIMG}}/g, porte.image)
    .replace(/{{alt}}/g, porte.alt)
    .replace(/{{Prix}}/g, porte.prix);
    clone.firstElementChild.innerHTML = newContent
    template.parentNode.appendChild(clone);
}