EXTENSION = pg_string_extension
DATA = pg_string_extension--0.1.sql
MODULES = pg_string_extension
REGRESS = pg_string_extension

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
