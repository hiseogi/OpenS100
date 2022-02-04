<?xml version="1.0" encoding="UTF-8"?>

<xsl:transform xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
   <xsl:output method="xml" encoding="UTF-8" indent="yes"/>
   <xsl:template match="FerryRoute[@primitive='Surface']" priority="1">
      <pointInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25030</viewingGroup>
         <displayPlane>UNDERRADAR</displayPlane>
         <drawingPriority>9</drawingPriority>
         <symbol reference="FRYARE51">
            <areaPlacement placementMode="VisibleParts"/>
         </symbol>
      </pointInstruction>
      <lineInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25030</viewingGroup>
         <displayPlane>UNDERRADAR</displayPlane>
         <drawingPriority>9</drawingPriority>
         <xsl:call-template name="simpleLineStyle">
            <xsl:with-param name="style">dash</xsl:with-param>
            <xsl:with-param name="width">0.64</xsl:with-param>
            <xsl:with-param name="colour">CHMGD</xsl:with-param>
         </xsl:call-template>
      </lineInstruction>
   </xsl:template>
   <xsl:template match="FerryRoute[@primitive='Surface' and categoryOfFerry=2]" priority="2">
      <pointInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25030</viewingGroup>
         <displayPlane>UNDERRADAR</displayPlane>
         <drawingPriority>9</drawingPriority>
         <symbol reference="FRYARE52">
            <areaPlacement placementMode="VisibleParts"/>
         </symbol>
      </pointInstruction>
      <lineInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25030</viewingGroup>
         <displayPlane>UNDERRADAR</displayPlane>
         <drawingPriority>9</drawingPriority>
         <xsl:call-template name="simpleLineStyle">
            <xsl:with-param name="style">dash</xsl:with-param>
            <xsl:with-param name="width">0.64</xsl:with-param>
            <xsl:with-param name="colour">CHBLK</xsl:with-param>
         </xsl:call-template>
      </lineInstruction>
   </xsl:template>
</xsl:transform>