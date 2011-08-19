json=commandArgs(TRUE)[1];

library('opal');

params=fromJSON(json);

opals <- opal.login(url=params$urls, opts=params$curlopts);

table = paste(params$datasource, params$table, sep=".");
for(var in params$variables) {
  #timestamp();
  for(study  in names(params$tables)) {
    table = params$tables[[study]];
    path = paste(table, var, sep=":");
    cat(paste('Preparing variable ', var, 'for study', study, '\n'));
    timestamp();
    datashield.assign(opals[[study]], var, path);
  }
}
timestamp();
print(datashield.glm(opals, params$model, glmparams=params$glm));