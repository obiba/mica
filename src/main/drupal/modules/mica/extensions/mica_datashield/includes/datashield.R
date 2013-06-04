json=commandArgs(TRUE)[1];

library('opal');

params=fromJSON(json);
opals <- opal.login(url=params$urls, opts=params$curlopts);

table = paste(params$datasource, params$table, sep=".");
for(var in params$variables) {
  for(study  in names(params$tables)) {
    table = params$tables[[study]];
    path = paste(table, var, sep=":");
    cat(paste('Preparing variable', var, 'for study', study, ':', path, '\n'));
    timestamp();
    datashield.assign(opals[[study]], var, path);
  }
}
timestamp();
cat(paste('Model: ', params$model, '\n'));
cat(paste('Family: ', params$glm$family, '\n'));

cmd<-paste('datashield.glm(opals,',params$model,',as.name("',params$glm$family,'"), 20)',sep="");
cat(paste('Command: ',cmd,'\n'));
print(eval(parse(text=cmd)));
