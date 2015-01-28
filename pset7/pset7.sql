DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(11) NOT NULL,
  `transaction` varchar(255) NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `symbol` varchar(255) NOT NULL,
  `shares` int(11) NOT NULL,
  `price` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (10,'BUY','2013-03-23 18:49:05','DNV.V',100,0.215),(10,'BUY','2013-03-23 18:49:40','GOOG',39,810.31),(10,'BUY','2013-03-23 18:50:36','GOOG',20,810.31),(10,'SELL','2013-03-23 18:57:01','GOOG',59,810.31),(7,'BUY','2013-03-23 19:03:05','GOOG',3,810.31),(7,'BUY','2013-03-23 19:03:21','AA',20,8.45);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolio`
--

DROP TABLE IF EXISTS `portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolio` (
  `id` int(10) unsigned NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolio`
--

LOCK TABLES `portfolio` WRITE;
/*!40000 ALTER TABLE `portfolio` DISABLE KEYS */;
INSERT INTO `portfolio` VALUES (1,'AAPL',20),(1,'AMZN',40),(2,'T',20),(3,'AAPL',50),(3,'BAC',30),(4,'AMZN',150),(5,'AA',200),(7,'AA',20),(7,'GOOG',3),(10,'AA',10),(10,'AAPL',200),(10,'DNV.V',100),(10,'T',100);
/*!40000 ALTER TABLE `portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'caesar','$1$50$GHABNWBNE/o4VL7QjmQ6x0',10000.0000),(2,'cs50','$1$50$ceNa7BV5AoVQqilACNLuC1',10000.0000),(3,'jharvard','$1$50$RX3wnAMNrGIbgzbRYrxM1/',10000.0000),(4,'malan','$1$HA$azTGIMVlmPi9W9Y12cYSj/',10000.0000),(5,'nate','$1$50$sUyTaTbiSKVPZCpjJckan0',10000.0000),(6,'rbowden','$1$50$lJS9HiGK6sphej8c4bnbX.',10000.0000),(7,'skroob','$1$50$euBi4ugiJmbpIbvTTfmfI.',7400.0700),(8,'tmacwilliam','$1$50$91ya4AroFPepdLpiX.bdP1',10000.0000),(9,'zamyla','$1$50$Suq.MOtQj51maavfKvFsW1',10000.0000),(10,'jmhawkins','$1$ecAoMAqX$trtHj77PEjwSXVKCdy/Qj0',47818.2900);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
