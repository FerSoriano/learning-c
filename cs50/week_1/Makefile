.PHONY: %

%:
	@if [ -f "$@.c" ]; then \
		clang -o out/$@ $@.c && ./out/$@; \
	else \
		echo "Error: $@.c not found"; \
		exit 1; \
	fi