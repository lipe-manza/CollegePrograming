const nome = () => {
  document.getElementById("ipt").value;
  document.getElementById("ipt2").value;
  let primeiroNome = document.getElementById("ipt").value;
  let segundoNome = document.getElementById("ipt2").value;
  let objeto = {
    primeiro_nome: primeiroNome,
    segundo_nome: segundoNome,
  };
  document.getElementById(
    "mostrar"
  ).innerText = `primeiro nome: ${objeto.primeiro_nome}\n segundo nome: ${objeto.segundo_nome}`;
};
