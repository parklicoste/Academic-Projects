function getRecipes() {
    let ingredient = document.getElementById('ingredient').value
    let ingredientDiv = document.getElementById('recipes')
    ingredientDiv.innerHTML = ''

    let xhr = new XMLHttpRequest()
    xhr.onreadystatechange = () => {
        if (xhr.readyState == 4 && xhr.status == 200) {
            let response = JSON.parse(xhr.responseText)
            let recipes = response.recipes  // getting all the recipes in response
            //console.log("is it coming inside")

            for (let card of recipes) { // running a loop for each recipe with image and  making a card of image with name
              //
                ingredientDiv.innerHTML  += `
                <div class="card">
                    <a href="${card.f2f_url}" target="_blank">
                        <img src=${card.image_url} />
                        <h2>${card.title}</h2>
                    </a>
                </div>
            `

            }
        }
    }
    xhr.open('GET', `/api?ingredient=${ingredient}`, true)
    xhr.send()                  //sending the data in /api
}
//Attach Enter-key Handler
const ENTER=13
document.getElementById("ingredient")
    .addEventListener("keyup", function(event) {
    event.preventDefault();
    if (event.keyCode === ENTER) {
        document.getElementById("submit").click();
    }
});
document.addEventListener('DOMContentLoaded',function(){
	document.getElementById("submit").click();
});
