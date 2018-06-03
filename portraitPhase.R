rm(list=ls())             
library(colorspace)


# | ainit | T | S/L |
data<-read.table("SimulationOutputs.csv", header = FALSE, sep = ",", dec=".")
names(data)<-c("ainit","T","result")

# Séparation des différents états du reste des données
extinction<-subset(data,data$result==-1)
exclusion<-subset(data,data$result==0)
cohabitation<-subset(data,data$result>0)
cohabitation <- cohabitation[order(cohabitation$result), ] 
n <- as.numeric(length(cohabitation$T))
#c <- 1
# Echelle de couleurs
color=heat_hcl(length(cohabitation$result))[rank(cohabitation$result)]

# Affichage
par(mar=c(5.1,4.1,4.1,8.1), xpd=TRUE)
plot(extinction$ainit,extinction$T, col='black', pch=15, 
     xlim=c(min(data$ainit),max(data$ainit)), ylim=c(min(data$T),max(data$T)))
points(exclusion$ainit,exclusion$T, col="#990033", pch=15)
points(cohabitation$ainit,cohabitation$T, col=color, pch=15)
legend("topright",title="S/L",inset=c(-0.15,0),pch=15,col=color,
       legend=seq(min(cohabitation$result),max(cohabitation$result),length.out = length(color)))


#hey <- ggplot(cohabitation, aes(x=cohabitation$ainit, y=cohabitation$T, color=cohabitation$result))
#hey + geom_point(size=6) + scale_color_gradient(low="#D33F6A", high="#E2E6BD")