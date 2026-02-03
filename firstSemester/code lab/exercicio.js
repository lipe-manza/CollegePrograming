const favoritos = [];

const forms = document.querySelector('#formFavorito');
const input = document.querySelector('#inputFavorito');
const listaFilmes = document.querySelector('#lista');
const contadorFilmes = document.querySelector('#contador');

function adicionarFilme(texto) {
    favoritos.push(texto);
}

function atualizarContador() {
    contadorFilmes.textContent = favoritos.length;
}

function renderizarLista() {
    listaFilmes.textContent = '';

    favoritos.forEach((texto) => {
        const li = document.createElement('li');
        li.className = 'item';

        const span = document.createElement('span');
        span.textContent = texto;

        li.appendChild(span);
        listaFilmes.appendChild(li);
    });
}

forms.addEventListener('submit', e => {
    e.preventDefault();
    const nomeFilme = input.value.trim();
    if (!nomeFilme) return;
    adicionarFilme(nomeFilme);
    input.value = '';
    renderizarLista();
    atualizarContador();
})