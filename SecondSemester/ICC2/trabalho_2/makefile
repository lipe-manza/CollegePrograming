# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99

# Diretórios e arquivos
TARGET = trabalho_2
OUTPUT_DIR = output
RESULTS_DIR = resultados

SOURCES = trabalho_2.c util.c
OBJECTS = $(SOURCES:.c=.o)

# Alvo padrão
all: $(OUTPUT_DIR) $(RESULTS_DIR) $(OUTPUT_DIR)/$(TARGET)

# Cria diretórios necessários
$(OUTPUT_DIR):
	@mkdir -p $(OUTPUT_DIR)
	@echo "Pasta $(OUTPUT_DIR)/ criada."

$(RESULTS_DIR):
	@mkdir -p $(RESULTS_DIR)
	@echo "Pasta $(RESULTS_DIR)/ criada."

# Compila o executável dentro de output/
$(OUTPUT_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Executável $(TARGET) compilado com sucesso em $(OUTPUT_DIR)/!"

# Compila arquivos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# =========================================================
# EXECUÇÃO
# =========================================================

# Executa o programa uma vez — você insere o método manualmente
run: all
	@echo "Digite o número do método de ordenação (1–9):"
	@read metodo; \
	echo $$metodo | ./$(OUTPUT_DIR)/$(TARGET)

# Executa todos os 9 métodos automaticamente
run_all: all
	@echo "Executando todos os 9 métodos de ordenação..."
	@for i in 1 2 3 4 5 6 7 8 9; do \
		echo "==> Método $$i"; \
		echo $$i | ./$(OUTPUT_DIR)/$(TARGET); \
	done
	@echo "Execuções concluídas. Resultados em $(RESULTS_DIR)/"

# =========================================================
# RESULTADOS
# =========================================================

# Lista resultados gerados
list_results:
	@if [ -d "$(RESULTS_DIR)" ] && [ -n "$$(ls -A $(RESULTS_DIR) 2>/dev/null)" ]; then \
		echo "=== Arquivos de Resultado ==="; \
		ls -lh $(RESULTS_DIR)/; \
	else \
		echo "Nenhum resultado encontrado em $(RESULTS_DIR)/"; \
	fi

# Mostra conteúdo de um resultado específico (use: make show_result ALGO=1)
show_result:
	@if [ -z "$(ALGO)" ]; then \
		echo "Uso: make show_result ALGO=<número 1–9>"; \
	else \
		if [ -f "$(RESULTS_DIR)/resultado_$(ALGO).csv" ]; then \
			echo "=== Resultado do Algoritmo $(ALGO) ==="; \
			cat $(RESULTS_DIR)/resultado_$(ALGO).csv; \
		else \
			echo "Arquivo não encontrado: $(RESULTS_DIR)/resultado_$(ALGO).csv"; \
		fi; \
	fi

# =========================================================
# LIMPEZA
# =========================================================

clean:
	@rm -f $(OBJECTS)
	@rm -f $(OUTPUT_DIR)/$(TARGET)
	@echo "Arquivos compilados removidos."

clean_all: clean
	@rm -rf $(RESULTS_DIR)
	@echo "Tudo limpo! Pasta $(RESULTS_DIR)/ removida."

# =========================================================
# AJUDA
# =========================================================

help:
	@echo "=== Comandos Disponíveis ==="
	@echo "  make                 - Compila o programa (output/)"
	@echo "  make run             - Executa o programa (você escolhe o método)"
	@echo "  make run_all         - Executa todos os 9 métodos automaticamente"
	@echo "  make list_results    - Lista arquivos de resultado"
	@echo "  make show_result ALGO=N - Mostra o resultado do algoritmo N"
	@echo "  make clean           - Remove arquivos compilados"
	@echo "  make clean_all       - Remove tudo (compilados + resultados)"
	@echo "  make help            - Mostra esta mensagem"

.PHONY: all run run_all list_results show_result clean clean_all help
