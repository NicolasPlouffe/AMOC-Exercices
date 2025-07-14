async function RecevoirEtat() {
    let reponse = await fetch("api/compacteur", {
        method: "GET",
        headers: {
            "Content-Type": "application/json"
        }
    })
    return await reponse.text()
}

async function ChangerEtat(etat) {
    await fetch(`api/compacteur?etat=${etat}`, {
        method: "PUT",
        headers: {
            "Content-Type": "application/json"
        },
    })
}

async function RecevoirNbCanettes() {
    let reponse = await fetch("api/canettes/compacte", {
        method: "GET",
        headers: {
            "Content-Type": "application/json"
        }
    })
    return await reponse.text()
}

async function ReinialiserNbCanettes() {
    await fetch("api/canettes/reinitialise", {
        method: "PUT",
        headers: {
            "Content-Type": "application/json"
        },
    })
}

async function RecevoirMontantVerse() {
    let reponse = await fetch("api/montant/verse", {
        method: "GET",
        headers: {
            "Content-Type": "application/json"
        }
    })
    return await reponse.text()
}

async function RecevoirEmplacement() {
    let reponse = await fetch("api/emplacement", {
        method: "GET",
        headers: {
            "Content-Type": "application/json"
        }
    })
    return await reponse.text()
}

async function EnvoyerNouvelEmplacement(){
    let nouvelEmplacement = document.getElementById("nouvelEmplacement").value ?? "Entreposage"
    await fetch(`api/emplacement?emplacement=${encodeURIComponent(nouvelEmplacement)}`, {
        method: "PUT",
        headers: {
            "Content-Type": "application/json"
        },
    })
}

function AfficherInfos() {
    const etat = document.getElementById("etat")
    const nbCanettes = document.getElementById("nbCanettes")
    const montantVerse = document.getElementById("montantVerse")
    const emplacement = document.getElementById("emplacement")

    RecevoirEtat()
        .then(response => {
            etat.innerText = response
        })
    RecevoirNbCanettes()
        .then(response => {
            nbCanettes.innerText = response
        })
    RecevoirMontantVerse()
        .then(response => {
            montantVerse.innerText = response
        })
    RecevoirEmplacement()
        .then(response => {
            emplacement.innerText = response
        })

}

document.addEventListener("DOMContentLoaded", () => {
    AfficherInfos()
    const boutonEtat = document.getElementById("boutonEtat")
    boutonEtat.addEventListener("click", async () => {
        let etat = boutonEtat.innerText === "Démarrer" ? "actif" : "inactif"
        await ChangerEtat(etat)
        boutonEtat.innerText = boutonEtat.innerText === "Démarrer" ? "Arrêter" : "Démarrer"
        AfficherInfos()
    })
    const boutonReinitialiser = document.getElementById("boutonReinitialiser")
    boutonReinitialiser.addEventListener("click", async () => {
        await ReinialiserNbCanettes()
        AfficherInfos()
    })
    const boutonNouvelEmplacement = document.getElementById("boutonEmplacement")
    boutonNouvelEmplacement.addEventListener("click", async () => {
        await EnvoyerNouvelEmplacement()
        AfficherInfos()
    })
})

setInterval(AfficherInfos, 1000)