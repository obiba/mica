json=commandArgs(TRUE)[1];

library('opal');

params=fromJSON(json);

opals <- opal.login(url=params$studies, opts=params$curlopts);

table = paste(params$datasource, params$table, sep=".");
for(var in params$variables) {
  datashield.assign(opals, var, paste(table, var, sep=":"));
#  datashield.assign(opals, var, quote(c(1:3)));
}

print(datashield.glm(opals, params$model, glmparams=params$glm));