
import com.bulenkov.darcula.DarculaLaf;
import javax.swing.UIManager;
import javax.swing.plaf.basic.BasicLookAndFeel;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ksdfg
 */
import java.io.FileNotFoundException;
import org.json.simple.JSONObject; 
import java.io.PrintWriter;
import org.json.simple.parser.*;
import java.io.FileReader;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JLabel;

public class mainFrame extends javax.swing.JFrame {
    
    //JSONObject that everybody is going to use - might as well declare it just once.
    JSONObject meow;
    
    /**
     * Creates new form mainFrame
     */
    public mainFrame() {    
        
        try {
            meow = (JSONObject) new JSONParser().parse(new FileReader("meow.json"));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(mainFrame.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException | ParseException ex) {
            Logger.getLogger(mainFrame.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        dsTh = new javax.swing.JLabel();
        dsPr = new javax.swing.JLabel();
        dsThAtt = new javax.swing.JButton();
        dsPrAtt = new javax.swing.JButton();
        sepmThAtt = new javax.swing.JButton();
        sepmTh = new javax.swing.JLabel();
        sepmPrAtt = new javax.swing.JButton();
        sepmPr = new javax.swing.JLabel();
        osThAtt = new javax.swing.JButton();
        osTh = new javax.swing.JLabel();
        osPrAtt = new javax.swing.JButton();
        osPr = new javax.swing.JLabel();
        mmcThAtt = new javax.swing.JButton();
        mmcTh = new javax.swing.JLabel();
        mmcPrAtt = new javax.swing.JButton();
        mmcPr = new javax.swing.JLabel();
        attendaceDisplay = new javax.swing.JLabel();
        dsThMiss = new javax.swing.JButton();
        sepmThMiss = new javax.swing.JButton();
        sepmPrMiss = new javax.swing.JButton();
        dsPrMiss = new javax.swing.JButton();
        osThMiss = new javax.swing.JButton();
        osPrMiss = new javax.swing.JButton();
        mmcThMiss = new javax.swing.JButton();
        mmcPrMiss = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setPreferredSize(new java.awt.Dimension(600, 600));
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowOpened(java.awt.event.WindowEvent evt) {
                formWindowOpened(evt);
            }
        });

        dsTh.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        dsTh.setText("1");
        dsTh.setBorder(javax.swing.BorderFactory.createTitledBorder("DS Theory"));

        dsPr.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        dsPr.setText("2");
        dsPr.setBorder(javax.swing.BorderFactory.createTitledBorder("DS Pracs"));

        dsThAtt.setText("+");
        dsThAtt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                dsThAttActionPerformed(evt);
            }
        });

        dsPrAtt.setText("+");
        dsPrAtt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                dsPrAttActionPerformed(evt);
            }
        });

        sepmThAtt.setText("+");
        sepmThAtt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sepmThAttActionPerformed(evt);
            }
        });

        sepmTh.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        sepmTh.setText("3");
        sepmTh.setBorder(javax.swing.BorderFactory.createTitledBorder("SEPM Theory"));

        sepmPrAtt.setText("+");
        sepmPrAtt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sepmPrAttActionPerformed(evt);
            }
        });

        sepmPr.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        sepmPr.setText("4");
        sepmPr.setBorder(javax.swing.BorderFactory.createTitledBorder("SEPM Pracs"));

        osThAtt.setText("+");
        osThAtt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                osThAttActionPerformed(evt);
            }
        });

        osTh.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        osTh.setText("0");
        osTh.setBorder(javax.swing.BorderFactory.createTitledBorder("OS Theory"));

        osPrAtt.setText("+");
        osPrAtt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                osPrAttActionPerformed(evt);
            }
        });

        osPr.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        osPr.setText("0");
        osPr.setBorder(javax.swing.BorderFactory.createTitledBorder("OS Pracs"));

        mmcThAtt.setText("+");
        mmcThAtt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mmcThAttActionPerformed(evt);
            }
        });

        mmcTh.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        mmcTh.setText("0");
        mmcTh.setBorder(javax.swing.BorderFactory.createTitledBorder("MMC Theory"));

        mmcPrAtt.setText("+");
        mmcPrAtt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mmcPrAttActionPerformed(evt);
            }
        });

        mmcPr.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        mmcPr.setText("0");
        mmcPr.setBorder(javax.swing.BorderFactory.createTitledBorder("MMC Pracs"));

        attendaceDisplay.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        attendaceDisplay.setText("0");
        attendaceDisplay.setBorder(javax.swing.BorderFactory.createTitledBorder("Attendance"));

        dsThMiss.setText("-");
        dsThMiss.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                dsThMissActionPerformed(evt);
            }
        });

        sepmThMiss.setText("-");
        sepmThMiss.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sepmThMissActionPerformed(evt);
            }
        });

        sepmPrMiss.setText("-");
        sepmPrMiss.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sepmPrMissActionPerformed(evt);
            }
        });

        dsPrMiss.setText("-");
        dsPrMiss.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                dsPrMissActionPerformed(evt);
            }
        });

        osThMiss.setText("-");
        osThMiss.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                osThMissActionPerformed(evt);
            }
        });

        osPrMiss.setText("-");
        osPrMiss.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                osPrMissActionPerformed(evt);
            }
        });

        mmcThMiss.setText("-");
        mmcThMiss.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mmcThMissActionPerformed(evt);
            }
        });

        mmcPrMiss.setText("-");
        mmcPrMiss.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mmcPrMissActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(112, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(attendaceDisplay, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                                .addComponent(mmcThAtt)
                                .addGap(18, 18, 18)
                                .addComponent(mmcTh, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                                .addComponent(osPrAtt)
                                .addGap(18, 18, 18)
                                .addComponent(osPr, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                                .addComponent(osThAtt)
                                .addGap(18, 18, 18)
                                .addComponent(osTh, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                                .addComponent(sepmPrAtt)
                                .addGap(18, 18, 18)
                                .addComponent(sepmPr, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                                .addComponent(dsPrAtt)
                                .addGap(18, 18, 18)
                                .addComponent(dsPr, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                                .addComponent(mmcPrAtt)
                                .addGap(18, 18, 18)
                                .addComponent(mmcPr, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                                .addComponent(sepmThAtt)
                                .addGap(18, 18, 18)
                                .addComponent(sepmTh, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                                .addComponent(dsThAtt)
                                .addGap(18, 18, 18)
                                .addComponent(dsTh, javax.swing.GroupLayout.PREFERRED_SIZE, 123, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(dsThMiss)
                            .addComponent(sepmThMiss)
                            .addComponent(sepmPrMiss)
                            .addComponent(dsPrMiss)
                            .addComponent(osThMiss)
                            .addComponent(osPrMiss)
                            .addComponent(mmcThMiss)
                            .addComponent(mmcPrMiss))))
                .addContainerGap(112, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(28, 28, 28)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(dsTh)
                    .addComponent(dsThMiss)
                    .addComponent(dsThAtt))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(dsPr)
                    .addComponent(dsPrAtt)
                    .addComponent(dsPrMiss))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(sepmTh)
                    .addComponent(sepmThAtt)
                    .addComponent(sepmThMiss))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(sepmPr)
                    .addComponent(sepmPrMiss)
                    .addComponent(sepmPrAtt))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(osTh)
                    .addComponent(osThAtt)
                    .addComponent(osThMiss))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(osPr)
                    .addComponent(osPrAtt)
                    .addComponent(osPrMiss))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(mmcTh)
                    .addComponent(mmcThAtt)
                    .addComponent(mmcThMiss))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(mmcPr)
                    .addComponent(mmcPrAtt)
                    .addComponent(mmcPrMiss))
                .addGap(18, 18, 18)
                .addComponent(attendaceDisplay)
                .addContainerGap(10, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    //calculate total attendance
    public double calculate(){
        long att = 0, tot = 0;
        double nyan = 0;   //var that stores attendance lel
        
        //calculate total number of lectures attended
        att += (long) meow.get("dsTh");
        att += (long) meow.get("dsPr");
        att += (long) meow.get("osTh");
        att += (long) meow.get("osPr");
        att += (long) meow.get("sepmTh");
        att += (long) meow.get("sepmPr");
        att += (long) meow.get("mmcTh");
        att += (long) meow.get("mmcPr");
        
        //calculate total number of lectures occurred
        tot += (long) meow.get("dsThTot");
        tot += (long) meow.get("dsPrTot");
        tot += (long) meow.get("osThTot");
        tot += (long) meow.get("osPrTot");
        tot += (long) meow.get("sepmThTot");
        tot += (long) meow.get("sepmPrTot");
        tot += (long) meow.get("mmcThTot");
        tot += (long) meow.get("mmcPrTot");
        
        if(tot != 0)
            nyan = att * 100 / tot; //calculate total attendance
        
        return nyan;
    }
    
    //change the attendance in a subject
    public void change(String subject, JLabel display, boolean attended){
        long att = (long) meow.get(subject);  //get numbr of lectures attended
        if(attended){
            att++;
            meow.put(subject, att); //change number of lectures attended in json
        }
        
        long tot = (long) meow.get(subject + "Tot");  //get total number of lectures
        tot++;
        meow.put(subject+"Tot", tot);   //change total number of lectures in json
        
        
        //apply changes to json file
        try (PrintWriter pw = new PrintWriter("meow.json")) {
            pw.write(meow.toJSONString());
            pw.flush();
            pw.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(mainFrame.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        display.setText(att + " / " + tot);
        
        attendaceDisplay.setText("" + calculate());
    }
    
    //initially display current status
    private void formWindowOpened(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowOpened
        // TODO add your handling code here:
        
        //ds
        dsTh.setText(meow.get("dsTh") + " / " + meow.get("dsThTot"));
        dsPr.setText(meow.get("dsPr") + " / " + meow.get("dsPrTot"));
        
        //os
        osTh.setText(meow.get("osTh") + " / " + meow.get("osThTot"));
        osPr.setText(meow.get("osPr") + " / " + meow.get("osPrTot"));
        
        //sepm
        sepmTh.setText(meow.get("sepmTh") + " / " + meow.get("sepmThTot"));
        sepmPr.setText(meow.get("sepmPr") + " / " + meow.get("sepmPrTot"));
        
        //mmc
        mmcTh.setText(meow.get("sepmTh") + " / " + meow.get("sepmThTot"));
        mmcPr.setText(meow.get("sepmPr") + " / " + meow.get("sepmPrTot"));
        
        //overall attendance
        attendaceDisplay.setText("" + calculate());
    }//GEN-LAST:event_formWindowOpened

    private void dsThAttActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_dsThAttActionPerformed
        // TODO add your handling code here:
        change("dsTh", dsTh, true);
    }//GEN-LAST:event_dsThAttActionPerformed

    private void dsThMissActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_dsThMissActionPerformed
        // TODO add your handling code here:
        change("dsTh", dsTh, false);
    }//GEN-LAST:event_dsThMissActionPerformed

    private void dsPrAttActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_dsPrAttActionPerformed
        // TODO add your handling code here:
        change("dsPr", dsPr, true);
    }//GEN-LAST:event_dsPrAttActionPerformed

    private void dsPrMissActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_dsPrMissActionPerformed
        // TODO add your handling code here:
        change("dsPr", dsPr, false);
    }//GEN-LAST:event_dsPrMissActionPerformed

    private void sepmThAttActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sepmThAttActionPerformed
        // TODO add your handling code here:
        change("sepmTh", sepmTh, true);
    }//GEN-LAST:event_sepmThAttActionPerformed

    private void sepmPrAttActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sepmPrAttActionPerformed
        // TODO add your handling code here:
        change("sepmPr", sepmPr, true);
    }//GEN-LAST:event_sepmPrAttActionPerformed

    private void sepmThMissActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sepmThMissActionPerformed
        // TODO add your handling code here:
        change("sepmTh", sepmTh, false);
    }//GEN-LAST:event_sepmThMissActionPerformed

    private void sepmPrMissActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sepmPrMissActionPerformed
        // TODO add your handling code here:
        change("sepmPr", sepmPr, false);
    }//GEN-LAST:event_sepmPrMissActionPerformed

    private void osThAttActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_osThAttActionPerformed
        // TODO add your handling code here:
        change("osTh", osTh, true);
    }//GEN-LAST:event_osThAttActionPerformed

    private void osThMissActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_osThMissActionPerformed
        // TODO add your handling code here:
        change("osTh", osTh, false);
    }//GEN-LAST:event_osThMissActionPerformed

    private void osPrAttActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_osPrAttActionPerformed
        // TODO add your handling code here:
        change("osPr", osPr, true);
    }//GEN-LAST:event_osPrAttActionPerformed

    private void osPrMissActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_osPrMissActionPerformed
        // TODO add your handling code here:
        change("osPr", osPr, false);
    }//GEN-LAST:event_osPrMissActionPerformed

    private void mmcThAttActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_mmcThAttActionPerformed
        // TODO add your handling code here:
        change("mmcTh", mmcTh, true);
    }//GEN-LAST:event_mmcThAttActionPerformed

    private void mmcThMissActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_mmcThMissActionPerformed
        // TODO add your handling code here:
        change("mmcTh", mmcTh, false);
    }//GEN-LAST:event_mmcThMissActionPerformed

    private void mmcPrAttActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_mmcPrAttActionPerformed
        // TODO add your handling code here:
        change("mmcPr", mmcPr, true);
    }//GEN-LAST:event_mmcPrAttActionPerformed

    private void mmcPrMissActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_mmcPrMissActionPerformed
        // TODO add your handling code here:
        change("mmcPr", mmcPr, false);
    }//GEN-LAST:event_mmcPrMissActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            BasicLookAndFeel darcula = new DarculaLaf();
            UIManager.setLookAndFeel(darcula);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(mainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            new mainFrame().setVisible(true);
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel attendaceDisplay;
    private javax.swing.JLabel dsPr;
    private javax.swing.JButton dsPrAtt;
    private javax.swing.JButton dsPrMiss;
    private javax.swing.JLabel dsTh;
    private javax.swing.JButton dsThAtt;
    private javax.swing.JButton dsThMiss;
    private javax.swing.JLabel mmcPr;
    private javax.swing.JButton mmcPrAtt;
    private javax.swing.JButton mmcPrMiss;
    private javax.swing.JLabel mmcTh;
    private javax.swing.JButton mmcThAtt;
    private javax.swing.JButton mmcThMiss;
    private javax.swing.JLabel osPr;
    private javax.swing.JButton osPrAtt;
    private javax.swing.JButton osPrMiss;
    private javax.swing.JLabel osTh;
    private javax.swing.JButton osThAtt;
    private javax.swing.JButton osThMiss;
    private javax.swing.JLabel sepmPr;
    private javax.swing.JButton sepmPrAtt;
    private javax.swing.JButton sepmPrMiss;
    private javax.swing.JLabel sepmTh;
    private javax.swing.JButton sepmThAtt;
    private javax.swing.JButton sepmThMiss;
    // End of variables declaration//GEN-END:variables
}
