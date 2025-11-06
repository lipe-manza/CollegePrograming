function par() {
  if (x % 2 == 0) {
    return x;
  }
}
const vector = [];
function processar(vetor, par) {
  const newvector = [];
  for(let i=0 ; i<vector.length ; i++){
    newvector.push(par(vector[i]))
  }
}
