function clique() {
  let texto = document.querySelector("#texto");
  texto.style.color = "red";
}
function increase() {
  let numberelement = document.getElementById("number"); //get the element in the h2#number and give to numberelement
  let currentnumber = parseInt(numberelement.textContent); // current number do a cast on numberele
  currentnumber += 1;
  numberelement.textContent = currentnumber;
}
